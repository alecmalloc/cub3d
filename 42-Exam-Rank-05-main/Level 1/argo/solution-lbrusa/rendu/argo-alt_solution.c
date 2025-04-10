
#include "argo.h"

int	peek(FILE *stream)
{
	int	c;

	c = getc(stream);
	ungetc(c, stream);
	return (c);
}

void	unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("Unexpected token '%c'\n", peek(stream));
	else
		printf("Unexpected end of input\n");
}

int	accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return (1);
	}
	return (0);
}

int	expect(FILE *stream, char c)
{
	if (accept(stream, c))
	{
		return (1);
	}
	unexpected(stream);
	return (0);
}

// add your code here

// forward declaration
bool	parse_json(json *dst, FILE *stream);

/**
 * One of the json primary type.
 * I accept negative integers as well but I check
 * first if the '-' is followed by a number otherwise
 * I put it back to the stream and return 0
 */
bool	parse_integer(json *dst, FILE *stream)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if (accept(stream, '-'))
	{
		sign = -1;
		if (peek(stream) == EOF)
		{
			ungetc('-', stream);
			return (false);
		}
	}
	if (!isdigit(peek(stream)))
		return (false);
	// fscanf make it easier!
	if (fscanf(stream, "%d", &result) != 1)
		return (false);
	// I update the json struct with the result only at the end
	// to avoid storing still a 0 in case of error
	result *= sign;
	dst->type = INTEGER;
	dst->integer = result;
	return (true);
}

/**
 * I get the string from the stream and store it in a buffer
 * If I have a backslash I accept it and store it in the buffer
 * together with the next character. I return NULL freeing the buffer
 * if I reach the end of the file or if I don't find the closing quote
 *
 */
char	*get_str(FILE *stream)
{
	char	*buffer;
	int		i;

	buffer = malloc(1096 * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (peek(stream) != '"' && peek(stream) != EOF)
	{
		accept(stream, '\\');
		buffer[i++] = getc(stream);
	}
	if (peek(stream) == EOF || !expect(stream, '"'))
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

/**
 * Another json primary type. I store the string in the json struct
 * and return 0 for error if the get_str function returns NULL
 */
bool	parse_string(json *dst, FILE *stream)
{
	dst->type = STRING;
	dst->string = get_str(stream);
	if (!dst->string)
		return (false);
	return (true);
}

/**
 * Another json primary type. I store the key value pair in the json struct
 * the key is always a string and the value can be any json type, an integer,
 * a string or a map again which is a json...
 */
bool	parse_map(json *dst, FILE *stream)
{
	int	i;

	i = 0;
	dst->type = MAP;
	dst->map.data = malloc(256 * sizeof(pair));
	if (!dst->map.data)
		return (false);
	// careful here with the size of the map. It is not the same as
	// the index of the array...
	dst->map.size = 0;
	while (peek(stream) != '}' && peek(stream) != EOF)
	{
		// so i increment this immediately. Important!
		dst->map.size++;
		// the key is always a string
		if (accept(stream, '"'))
		{
			dst->map.data[i].key = get_str(stream);
			if (!dst->map.data[i].key)
				return (false);
		}
		else
			return (false);
		// the key is always followed by a colon and a value
		if (!accept(stream, ':') || !parse_json(&dst->map.data[i].value,
				stream))
			return (false);
		// I might have anotheer key value pair,
		// and if not i expect a closing bracket
		if (accept(stream, ','))
		{
			i++;
			continue ;
		}
	}
	// If I did not exit the loop with a closing bracket I return 0 for error
	if (!accept(stream, '}'))
		return (false);
	return (true);
}
/**
 * recursive function to parse json
 * I have three cases. Either the json is starting as an integer,
 * string or map. in case of map the function will call itself
 * recursively. if any of those cases fails I return -1
 */
bool	parse_json(json *dst, FILE *stream)
{
	if (isdigit(peek(stream)) || (peek(stream) == ('-')))
		return (parse_integer(dst, stream));
	else if (accept(stream, '"'))
		return (parse_string(dst, stream));
	else if (accept(stream, '{'))
		return (parse_map(dst, stream));
	else
		return (false);
	return (true);
}

/**
 * I use this as a wrapper to call parse_json and
 * check if there is any unexpected token when parsing is
 * finished otherwise I miss the last tokens which would give an
 * error
 */
int	argo(json *dst, FILE *stream)
{
	if (!parse_json(dst, stream) || peek(stream) != EOF)
	{
		unexpected(stream);
		return (-1);
	}
	return (1);
}
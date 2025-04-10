#include "argo.h"

int peek(FILE *stream) {
    int c = getc(stream);
    ungetc(c, stream);
    return c;
}

void unexpected(FILE *stream) {
    if (peek(stream) != EOF)
        printf("Unexpected token '%c'\n", peek(stream));
    else
        printf("Unexpected end of input\n");
}

int accept(FILE *stream, char c) {
    if (peek(stream) == c) {
        (void) getc(stream);
        return 1;
    }
    return 0;
}

int expect(FILE *stream, char c) {
    if (accept(stream, c)) {
        return 1;
    }
    unexpected(stream);
    return 0;
}



//solution below

int parse_int(json *dst, FILE *stream)
{
    dst->type = INTEGER;
    dst->integer = 0;
    while (isdigit(peek(stream)))
        dst->integer = dst->integer * 10 + getc(stream) - '0';
    return 1;
}

char *get_str(FILE *stream)
{
    char *buff = malloc(256 * sizeof(char));
    int i = 0;

    while (peek(stream) != '"' && peek(stream) != EOF) {
        accept(stream, '\\');
        if (peek(stream) != EOF)
            buff[i++] = getc(stream);
    }
    buff[i] = '\0';
    if (!expect(stream, '"')) {
        free(buff);
        return NULL;
    }
    return buff;
}

int parse_str(json *dst, FILE *stream)
{
    dst->type = STRING;
    dst->string = get_str(stream);
    if (!dst->string)
        return -1;
    return 1;
}

int parse_map(json *dst, FILE *stream)
{
    dst->type = MAP;
    dst->map.data = malloc(256 * sizeof(pair));
    if (!dst->map.data)
        return -1;

    int i = 0;
    dst->map.size = 0;
    while (peek(stream) != '}' && peek(stream) != EOF)
    {
        if (accept(stream, '"'))
            dst->map.data[i].key = get_str(stream);
        if (!dst->map.data[i].key)
            return -1;

        accept(stream, ':');
        accept(stream, ' ');

        if(peek(stream) == '{')
            argo(&dst->map.data[i].value, stream);
        else if (isdigit(peek(stream)))
            parse_int(&dst->map.data[i].value, stream);
        else if (peek(stream) == '}')
            return unexpected(stream), -1;

        accept(stream, ',');
        i++;
        dst->map.size++;
    }
    return 1;
}

int argo(json *dst, FILE *stream)
{
    if (isdigit(peek(stream)))
        return parse_int(dst, stream);
    else if (accept(stream, '"'))
        return parse_str(dst, stream);
    else if (accept(stream, '{'))
        return parse_map(dst, stream);
    unexpected(stream);
    return -1;
}

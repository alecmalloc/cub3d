#include "cubed.h"

static char	*skip_newlines(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp && *tmp == '\n')
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (tmp);
}

int	extract_map(t_parser *parser)
{
	char	*tmp;
	int		ret;
	
	tmp = skip_newlines(parser->fd);
	if (!tmp)
		return (MNF_ERR);
	ret = printf("%s", tmp);
	return (ret);
}

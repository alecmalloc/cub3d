#include "cubed.h"

static int	find_map(t_parser *parser, char **tmp)
{
	int		z;

	(*tmp) = get_next_line(parser->fd);
	while ((*tmp) && *(*tmp) == '\n')
	{
		free((*tmp));
		(*tmp) = get_next_line(parser->fd);
	}
	z = 0;
	while ((*tmp) && (*tmp)[z] && (ft_strchr(MAP_CHR, (*tmp)[z]) \
		|| (*tmp)[z] == '\n'))
		z++;
	if ((*tmp)[z] != '\0')
		return (free((*tmp)), WRL_ERR);
	return (0);
}

static int	map_store_append(char **map_store, char *append)
{
	char	*tmp;

	tmp = ft_strjoin(*map_store, append);
	if (!tmp)
		return (MALL_ERR);
	free(*map_store);
	*map_store = tmp;
	return (0);
}

static int	map_store(char **map_store, t_parser *parser, t_map *map)
{
	char	*tmp;
	int		len;
	int		ret;

	ret = find_map(parser, &tmp);
	if (ret)
		return (ret);
	while (tmp)
	{
		len = ft_strlen(tmp);
		if (len > map->x_len)
			map->x_len = len;
		ret = map_store_append(map_store, tmp);
		free(tmp);
		if (ret)
			return (ret);
		map->y_len++;
		tmp = get_next_line(parser->fd);
	}
	return (0);
}

int	extract_map(t_parser *parser)
{
	int		ret;

	ret = map_store(&parser->map->map_storage, parser, parser->map);
	if (ret)
		return (ret);
	ret = copy_map(parser->map);
	return (ret);
}

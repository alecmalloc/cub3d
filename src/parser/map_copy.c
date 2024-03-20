#include "cubed.h"

static int	alloc_map(t_map *map)
{
	int	z;

	z =0;
	map->map = (char **)malloc(sizeof(char *) * map->y_len);
	if (!map->map)
		return(MALL_ERR);
	while (z < map->x_len)
	{
		map->map[z] = malloc(sizeof(char) * map->x_len);
		if (!map->map[z])
			return (MALL_ERR);
		z++;
	}
	return (0);
}

static void	fill_rest_line(char *tmp, int len)
{
	while (len--)
	{
		*tmp = ' ';
		tmp++;
	}
	*tmp = '\0';
}
static int	map_copy(t_map *map)
{
	int	x;
	int	y;
	int	z;

	z = 0;
	y = 0;
	x = 0;
	while (map->map_storage[z])
	{
		if (map->map_storage[z] == '\n')
		{
			fill_rest_line(&(map->map[y][x]), map->x_len - x);
			x = 0;
			z++;
			y++;
		}
		map->map[y][x] = map->map_storage[z];
		x++;
		z++;
	}
	map->map[y] = NULL;
	return (0);
}

int	copy_map(t_map *map)
{
	int	ret;

	ret = alloc_map(map);
	if (ret)
		return (ret);
	ret = map_copy(map);
	if (ret)
		return (ret);
	ret = check_map(map);
	if (ret)
		return (ret);
	return (0);
}

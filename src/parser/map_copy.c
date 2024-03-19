#include "cuebd.h"

int	get_map_size(t_map *map, int fd_og)
{
	int		fd_tmp;
	int		x;
	int		y;
	char	*tmp;

	fd_tmp = fd_og;
	x = 0;
	y = 0;
	tmp = get_next_line(fd);
	while (tmp && *tmp == '\n')
	{
		free(tmp);
		tmp = get_next_line(fd_tmp);
	}
	while(tmp)
	{
		x = get_x_len(tmp;
		if ( x == 0)
			break;
		if (x < map->x)
			map->x = x;
		map->y++;
		free(tmp);
		tmp = get_next_line(fd_tmp);
	}
}

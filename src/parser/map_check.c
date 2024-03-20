#include "cubed.h"

int	wrong_char(t_map *map, int x, int y)
{
	if (!ft_strchr(MAP_CHR, map->map[y][x]))
		return (WCM_ERR);
	if (!map->map[y][x] || map->map[y][x] == ' ' || map->map[y][x] == '1')
		return (0);
	if ((x - 1 < 0) || (x + 1 > map->x_len) || (y - 1 < 0) || (y + 1 > map->y_len))
		return (OPW_ERR);
	if (ft_strchr(IMP_CHR, map->map[y - 1][x - 1]) && \
		ft_strchr(IMP_CHR, map->map[y - 1][x]) && \
		ft_strchr(IMP_CHR, map->map[y - 1][x + 1]) && \
		ft_strchr(IMP_CHR, map->map[y][x - 1]) && \
		ft_strchr(IMP_CHR, map->map[y][x + 1]) && \
		ft_strchr(IMP_CHR, map->map[y + 1][x - 1]) && \
		ft_strchr(IMP_CHR, map->map[y + 1][x]) && \
		ft_strchr(IMP_CHR, map->map[y + 1][x + 1]))
		return (0);
	return (OPW_ERR);
}

int	check_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while(map->map[y])
	{
		x = 0;
		while (map->map[y][x] && !wrong_char(map, x, y))
		{
			if (ft_strchr(PLR_CHR, map->map[y][x]))
			{
				if (map->player_dir != 0)
					return (DPL_ERR);
				map->player_dir = map->map[y][x];
				map->player_pos[0] = x;
				map->player_pos[1] = y;
			}
			x++;
		}
		if (wrong_char(map, x, y))
			return (wrong_char(map, x, y));
		y++;
	}
	return (0);	
}
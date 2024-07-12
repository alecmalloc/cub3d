#include "cubed.h"

int		ray_check_hit(t_cubed *cubed, t_ray *ray)
{
	int map_x;
	int map_y;
	char **map;

	map_x = (int)ray->map_x;
	map_y = (int)ray->map_y;
	map = cubed->parser->map->map;

	// printf("checking at x: %d y: %d\n", map_x, map_y);
	if (map[map_y][map_x] == '1')
		return (HIT_WALL);
	return (0);
}

int		ray_check_outside(t_cubed *cubed, t_ray *ray)
{
	if (ray->map_x < 0)
		return (OUT_ERR);
	if (ray->map_y < 0)
		return (OUT_ERR);
	if (ray->map_x >= cubed->parser->map->x_len)
		return (OUT_ERR);
	if (ray->map_y >= cubed->parser->map->y_len)
		return (OUT_ERR);
	return (0);
}


int		ray_check_hit_out(t_cubed *cubed, t_ray *ray)
{
	if (ray_check_outside(cubed, ray))
		return (OUT_ERR);
	if (ray_check_hit(cubed, ray))
		return (ray->hit = HIT_WALL);
	return (0);
}

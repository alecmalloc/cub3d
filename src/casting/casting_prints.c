#include "cubed.h"

void	print_ray(t_ray *ray)
{
	printf("ray angle: %f \n", ray->angle);
	//printf("ray step_x: %d \n", ray->step_x);
	//printf("ray step_y: %d \n", ray->step_y);
	printf("ray org_x: %f \n", ray->org_x);
	printf("ray org_y: %f \n", ray->org_y);
	//printf("ray len_x: %f \n", ray->len_x);
	//printf("ray len_y: %f \n", ray->len_y);
	printf("ray map_x: %f \n", ray->map_x);
	printf("ray map_y: %f \n", ray->map_y);
}

void	print_map_c(t_cubed *cubed)
{
	int y;
	char **map;
	map = cubed->parser->map->map;


	y = 0;
	while (map[y])
	{
		printf("%s\n", map[y]);
		y++;
	}
}
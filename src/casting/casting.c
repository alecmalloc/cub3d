#include "cubed.h"

void	set_steps_x_y(t_ray *ray)
{
	if (ray->angle > 90 && ray->angle < 270)
		ray->step_x = -1;
	if (ray->angle > 270 || ray->angle < 90)
		ray->step_x = 1;
	if (ray->angle > 180 && ray->angle < 360)
		ray->step_y = -1;
	if (ray->angle < 180 && ray->angle > 0)
		ray->step_y = 1;
}

void	calc_init_distance(t_ray *ray)
{
	if (ray->angle > 90 && ray->angle < 270)
	{
		ray->len_x = fabs((ray->org_x - (int)ray->org_x) / cos(ray->angle_r));
		ray->map_x = ray->org_x - fabs(ray->org_x - (int)ray->org_x);
	}
	if (ray->angle > 270 || ray->angle < 90)
	{
		ray->len_x = fabs(((int)ray->org_x + 1 - ray->org_x) / cos(ray->angle_r));
		ray->map_x = ray->org_x + fabs((int)ray->org_x + 1 - ray->org_x);
	}
	if (ray->angle < 180 && ray->angle > 0)
	{
		ray->len_y = fabs((ray->org_y - (int)ray->org_y) / sin(ray->angle_r));
		ray->map_y = ray->org_y - fabs(ray->org_y - (int)ray->org_y);
	}
	if (ray->angle > 180 && ray->angle < 360)
	{
		ray->len_y = fabs(((int)ray->org_y + 1 - ray->org_y) / sin(ray->angle_r));
		ray->map_y = ray->org_y + fabs((int)ray->org_y + 1 - ray->org_y);
	}
}

int		ray_check_hit(t_cubed *cubed, t_ray *ray)
{
	int map_x;
	int map_y;
	char **map;

	map_x = (int)ray->map_x;
	map_y = (int)ray->map_y;
	map = cubed->parser->map->map;

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

void	print_ray(t_ray *ray)
{
	printf("ray angle: %f \n", ray->angle);
	printf("ray step_x: %d \n", ray->step_x);
	printf("ray step_y: %d \n", ray->step_y);
	printf("ray org_x: %f \n", ray->org_x);
	printf("ray org_y: %f \n", ray->org_y);
	printf("ray len_x: %f \n", ray->len_x);
	printf("ray len_y: %f \n", ray->len_y);
	printf("ray map_x: %f \n", ray->map_x);
	printf("ray map_y: %f \n", ray->map_y);
}

void	print_map(t_cubed *cubed)
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

int		ray_check_hit_out(t_cubed *cubed, t_ray *ray)
{
	if (ray_check_outside(cubed, ray))
		return (OUT_ERR);
	if (ray_check_hit(cubed, ray))
		return (ray->hit = HIT_WALL);
	return (0);
}

void	ray_vector_x(t_cubed *cubed, t_ray *ray)
{
	ray->map_x += ray->step_x;
	if (ray->angle_r == (M_PI / 2) || ray->angle_r == ((3 * M_PI) / 2))
	{
		ray->len_x += 1e30;
		return;
	}
	ray->len_x += fabs(1 / cos(ray->angle_r));
	(void)cubed;
}

void	ray_vector_y(t_cubed *cubed, t_ray *ray)
{
	ray->map_y += ray->step_y;
	if (ray->angle_r == M_PI || ray->angle_r == 0)
	{
		ray->len_y += 1e30;
		return;
	}
	ray->len_y += fabs(1 / sin(ray->angle_r));
	printf("i len_y %f\n", ray->len_y);
	(void)cubed;
}

void	ray_calc_steps(t_cubed *cubed, t_ray *ray)
{
	// int hit;

	// hit = 0;

	set_steps_x_y(ray);
	calc_init_distance(ray);

	print_ray(ray);
	print_map(cubed);

	while (ray_check_hit_out(cubed, ray) == 0)
	{
		if (ray->len_x < ray->len_y)
			ray_vector_x(cubed, ray);
		else
			ray_vector_y(cubed, ray);
	}
	if (ray->hit != HIT_WALL)
		return;
	printf("i hit a wall at x: %f y: %f \n", ray->map_x, ray->map_y);
	printf("len_x: %f len_y: %f\n", ray->len_x, ray->len_y);

	(void)cubed;

}

int		init_ray(t_ray **ray, double angle, double org_x, double org_y)
{
	*ray = malloc(sizeof(t_ray));
	if (!(*ray))
		return (1);
	(*ray)->hit = 0;
	(*ray)->step_x = 0;
	(*ray)->step_y = 0;
	(*ray)->org_x = org_x;
	(*ray)->org_y = org_y;
	(*ray)->map_x = org_x;
	(*ray)->map_y = org_y;
	(*ray)->angle = angle;
	(*ray)->angle_r = conv_deg_rad(angle);
	(*ray)->len_x = 0;
	(*ray)->len_y = 0;
	return (0);
}

int		casting(t_cubed *cubed)
{
	t_ray	*ray;
	(void)cubed;

	ray = NULL;

	printf("dir: %f\n", cubed->game->dir);

	if (init_ray(&ray, cubed->game->dir, cubed->game->pos[0], cubed->game->pos[1]) != 0)
		return (MALL_ERR);
	ray_calc_steps(cubed, ray);

	free(ray);
	return (0);
}
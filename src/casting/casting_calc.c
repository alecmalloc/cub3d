#include "cubed.h"

void	calc_init_distance_x(t_ray *ray)
{
	if (ray->org_x == (int)ray->org_x)
		return ;
	if (ray->angle > 90 && ray->angle < 270)
	{
		ray->len_x = fabs((ray->org_x - (int)ray->org_x) * ray->delta_x);
		ray->map_x = ray->org_x - fabs(ray->org_x - (int)ray->org_x);
	}
	if (ray->angle > 270 || ray->angle < 90)
	{
		ray->len_x = fabs(((int)ray->org_x + 1 - ray->org_x) * ray->delta_y);
		ray->map_x = ray->org_x + fabs((int)ray->org_x + 1 - ray->org_x);
	}
}

void	calc_init_distance_y(t_ray *ray)
{
	if (ray->org_y == (int)ray->org_y)
		return ;
	if (ray->angle > 0 && ray->angle < 180)
	{
		ray->len_y = fabs((ray->org_y - (int)ray->org_y) * ray->delta_y);
		ray->map_y = ray->org_y - fabs(ray->org_y - (int)ray->org_y);
	}
	if (ray->angle > 180 && ray->angle < 360)
	{
		ray->len_y = fabs(((int)ray->org_y + 1 - ray->org_y) * ray->delta_y);
		ray->map_y = ray->org_y + fabs((int)ray->org_y + 1 - ray->org_y);
	}
}

void	calc_init_distance(t_ray *ray)
{
	calc_init_distance_x(ray);
	calc_init_distance_y(ray);
}

void	ray_calc_steps(t_cubed *cubed, t_ray *ray)
{
	double min_len;

	set_steps_x_y(ray);
	calc_init_distance(ray);

	print_ray(ray);
	// print_map_c(cubed);

	while (ray_check_hit_out(cubed, ray) == 0)
	{
		if (ray->len_x < ray->len_y)
			ray_vector_x(cubed, ray);
		else
			ray_vector_y(cubed, ray);
		printf("* mapx: %f mapy: %f \n", ray->map_x, ray->map_y);
		printf("-> lenx: %f leny: %f \n", ray->len_x, ray->len_y);
	}

	printf("dx: %f dy: %f\n", ray->delta_x, ray->delta_y);

	if (ray->hit == HIT_WALL)
		printf("hit wall x: %f y: %f\n", ray->map_x, ray->map_y);

	if (ray->hit != HIT_WALL)
		min_len = -1;
	else if (ray->len_x < ray->len_y)
		min_len = ray->len_x;
	else
		min_len = ray->len_y;

	printf("ray min dist: %f\n", min_len);

}
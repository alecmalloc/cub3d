#include "cubed.h"

void	calc_step_x(t_cubed *cubed, t_ray *ray)
{
	(void)cubed;
	if (ray->angle > 90 && ray->angle < 270)
	{
		if (ray->map_x == (int)ray->map_x)
			ray->step_x = -1;
		else
			ray->step_x = (int)ray->map_x - ray->map_x;
	}
	if (ray->angle > 270 || ray->angle < 90)
	{
		if (ray->map_x == (int)ray->map_x)
			ray->step_x = 1;
		else
			ray->step_x = ((int)ray->map_x + 1) - ray->map_x;
	}
}

void	calc_step_y(t_cubed *cubed, t_ray *ray)
{
	(void)cubed;
	if (ray->angle > 180 && ray->angle < 360)
	{
		if (ray->map_y == (int)ray->map_y)
			ray->step_y = 1;
		else
			ray->step_y = ((int)ray->map_y + 1) - ray->map_y;
	}
	if (ray->angle < 180 && ray->angle > 0)
	{
		if (ray->map_y == (int)ray->map_y)
			ray->step_y = -1;
		else
			ray->step_y = (int)ray->map_y - ray->map_y;
	}
}

void	ray_calc_steps(t_cubed *cubed, t_ray *ray)
{
	double min_len;

	print_ray(ray);

	while (ray_check_hit_out(cubed, ray) == 0)
	{
		calc_step_x(cubed, ray);
		calc_step_y(cubed, ray);
		printf("stepx: %f stepy %f\n", ray->step_x, ray->step_y);

		if ((ray->delta_x + ray->len_x) < (ray->delta_y + ray->len_y))
			ray_vector_x(cubed, ray);
		else
			ray_vector_y(cubed, ray);

		printf("* mapx: %f mapy: %f \n", ray->map_x, ray->map_y);
		printf("-> diffx %f diffy %f\n", (fabs(ray->map_x - ray->org_x)), ((fabs(ray->map_y - ray->org_y))));
		printf("--> lenx: %f leny: %f \n", ray->len_x, ray->len_y);
	}

	printf("dx: %f dy: %f\n", ray->delta_x, ray->delta_y);

	if (ray->hit == HIT_WALL)
		printf("hit wall x: %f y: %f\n", ray->map_x, ray->map_y);

	if (ray->hit != HIT_WALL)
		min_len = -1;
	else if (ray->len_x == 0 && ray->len_y > 0)
		min_len = ray->len_y;
	else if (ray->len_y == 0 && ray->len_x > 0)
		min_len = ray->len_x;
	else if (ray->len_x < ray->len_y)
		min_len = ray->len_x;
	else
		min_len = ray->len_y;

	printf("ray min dist: %f\n", min_len);

}
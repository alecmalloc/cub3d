#include "cubed.h"

void	calc_step_x(t_cubed *cubed, t_ray *ray)
{
	(void)cubed;
	if (ray->angle > 90 && ray->angle < 270)
		ray->step_x = -1;
	if (ray->angle > 270 || ray->angle < 90)
		if (ray->map_x == (int)ray->map_x)
			ray->step_x = 1;
}

void	calc_step_y(t_cubed *cubed, t_ray *ray)
{
	(void)cubed;
	if (ray->angle > 180 && ray->angle < 360)
		ray->step_y = 1;
	if (ray->angle < 180 && ray->angle > 0)
		ray->step_y = -1;
}

void	calc_dist_next_x(t_ray *ray)
{
	if ((int)ray->map_x == ray->map_x)
		ray->dist_next_x =  1;
	else
	{
		if (ray->step_x == 1)
			ray->dist_next_x = 1 - (ray->map_x - (int)ray->map_x);
		else
			ray->dist_next_x = (ray->map_x - (int)ray->map_x);
	}
}

void	calc_dist_next_y(t_ray *ray)
{
	if ((int)ray->map_y == ray->map_y)
		ray->dist_next_y =  1;
	else
	{
		if (ray->step_y == 1)
			ray->dist_next_y = 1 - (ray->map_y - (int)ray->map_y);
		else
			ray->dist_next_y = (ray->map_y - (int)ray->map_y);
	}
}

void	ray_calc_steps(t_cubed *cubed, t_ray *ray)
{
	double min_len;

	//print_ray(ray);
	printf("ray angle: %f\n", ray->angle);
	printf("dirx %f, diry %f\n", ray->dir_x, ray->dir_y);
	while (ray->hit == 0)
	{
		//printf("-----------------\n");
		calc_step_x(cubed, ray);
		calc_step_y(cubed, ray);
		//printf("stepx: %f stepy %f\n", ray->step_x, ray->step_y);

		calc_dist_next_x(ray);
		calc_dist_next_y(ray);
		if ((ray->dist_next_x * ray->delta_x) < (ray->dist_next_y * ray->delta_y))
			ray_vector_x(cubed, ray);
		else
			ray_vector_y(cubed, ray);

		//printf("* mapx: %f mapy: %f \n", ray->map_x, ray->map_y);
		// printf("len ray: %f \n", ray->len_ray);
		ray->hit = ray_check_hit(cubed, ray);
	}

	// printf("=================\n");
	if (ray->hit == HIT_WALL)
		printf("hit wall x: %d y: %d\n", (int)ray->map_x, (int)ray->map_y);

	min_len = ray->len_ray;

	printf("len ray: %f\n", min_len);

}
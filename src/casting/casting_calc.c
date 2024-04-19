#include "cubed.h"

void	ray_calc_steps(t_cubed *cubed, t_ray *ray)
{
	double min_len;

	// set_steps_x_y(ray);

	print_ray(ray);
	// print_map_c(cubed);

	while (ray_check_hit_out(cubed, ray) == 0)
	{
		calc_step_x(cubed, ray);
		calc_step_y(cubed, ray);
		printf("stepx: %f stepy %f\n", ray->step_x, ray->step_y);

		if ((ray->delta_x + ray->len_x) < (ray->delta_y + ray->delta_y))
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
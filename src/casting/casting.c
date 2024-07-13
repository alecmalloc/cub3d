#include "cubed.h"

void	set_steps_x_y(t_ray *ray)
{
	if (ray->angle > 90 && ray->angle < 270)
		ray->dist_next_x = (ray->org_x - ray->map_x) * ray->delta_x;
	if (ray->angle > 270 || ray->angle < 90)
		ray->dist_next_x = (ray->map_x + 1.0 - ray->org_x) * ray->delta_x;
	if (ray->angle > 180 && ray->angle < 360) 
		ray->dist_next_y = (ray->org_y - ray->map_y) * ray->delta_y;
	if (ray->angle < 180 && ray->angle > 0)
		ray->dist_next_y = (ray->map_y + 1.0 - ray->org_y) * ray->delta_y;

	if (ray->org_x == ray->map_x)
        ray->dist_next_x = ray->delta_x;
    if (ray->org_y == ray->map_y)
        ray->dist_next_y = ray->delta_y;
}

void	ray_vector_x(t_cubed *cubed, t_ray *ray)
{
	double y_dist;
	double x_dist;
	// printf("vy\n");

	x_dist = ray->dist_next_x;
	y_dist = (x_dist * ray->delta_x) / ray->delta_y;

	ray->map_x += x_dist * (ray->step_x);
	ray->map_y += y_dist * (ray->step_y);

	ray->len_ray += ray->dist_next_x * ray->delta_x;

	(void)cubed;
}

void	ray_vector_y(t_cubed *cubed, t_ray *ray)
{
	double y_dist;
	double x_dist;
	// printf("vy\n");

	y_dist = ray->dist_next_y;
	x_dist = (y_dist * ray->delta_y) / ray->delta_x;


	ray->map_y += y_dist * ray->step_y;
	ray->map_x += x_dist * ray->step_x;

	ray->len_ray += ray->dist_next_y * ray->delta_y;

	(void)cubed;
}

int		casting(t_cubed *cubed)
{
	double	angle;
	double	pos_x;
	double	pos_y;

	// printf("dir: %f\n", cubed->game->dir);

	// angle = cubed->game->dir;
	angle = 45;
	pos_x = cubed->game->pos[0];
	pos_y = cubed->game->pos[1];

	if (init_spread_rays(cubed, angle, pos_x, pos_y) != 0)
		return (MALL_ERR);

	// TESTING:
	// t_ray *ray;
	// if (init_ray(&ray, angle, pos_x, pos_y) != 0)
	// 	return (MALL_ERR);
	// ray_calc_steps(cubed, ray);
	// free(ray);
	// printf("---------------------\n");

	return (0);
}

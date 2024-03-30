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
	if (angle > 90 && angle < 270)
		*step_x = -1;
	if (angle > 270 || angle < 90)
		*step_x = 1;
	if (angle > 180 && angle < 360)
		*step_y = -1;
	if (angle < 180 && angle > 0)
		*step_y = 1;
}

void	ray_calc_steps(t_ray *ray)
{
	set_steps_x_y(ray);
	calc_init_distance(ray);
}

void	*init_ray(t_ray *ray, double angle, double org_x, double org_y)
{
	ray = malloc(sizeof(ray));
	if (!ray)
		return ((void *)1);
	ray->step_x = 0;
	ray->step_y = 0;
	ray->org_x = 0;
	ray->org_y = 0;
	ray->angle = angle;
	ray->ray_len_x = 0;
	ray->ray_len_y = 0;
	return (0);
}

void	*casting(t_cubed *cubed)
{
	t_ray *ray;
	double angle;
	(void)cubed;

	if (init_ray(ray, 180, 3.5, 3.5) == 0)
		return (MALL_ERR);
	ray_calc_steps(ray);
}
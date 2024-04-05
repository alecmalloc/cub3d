#include "cubed.h"

void	set_steps_x_y(t_ray *ray)
{
	if (ray->angle > 90 && ray->angle < 270)
		ray->step_x = -1;
	if (ray->angle > 270 || ray->angle < 90)
		ray->step_x = 1;
	if (ray->angle > 180 && ray->angle < 360)
		ray->step_y = 1;
	if (ray->angle < 180 && ray->angle > 0)
		ray->step_y = -1;
}



void	ray_vector_x(t_cubed *cubed, t_ray *ray)
{
	ray->map_x += ray->step_x;
	if (ray->angle_r == (M_PI / 2) || ray->angle_r == ((3 * M_PI) / 2))
	{
		ray->len_x += 1e30;
		return;
	}
	ray->len_x += ray->delta_x;
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
	ray->len_y += ray->delta_y;
	(void)cubed;
}

int		casting(t_cubed *cubed)
{
	double	angle;
	double	pos_x;
	double	pos_y;

	// printf("dir: %f\n", cubed->game->dir);

	angle = cubed->game->dir;
	pos_x = cubed->game->pos[0];
	pos_y = cubed->game->pos[1];

	if (init_spread_rays(cubed, angle, pos_x, pos_y) != 0)
		return (MALL_ERR);

	// t_ray *ray;
	// if (init_ray(&ray, 144, 12.5, 3.5) != 0)
	// 	return (MALL_ERR);
	// ray_calc_steps(cubed, ray);
	// free(ray);

	return (0);
}
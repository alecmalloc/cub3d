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
		ray->map_x = ray->org_x - ray->len_x;
	}
	if (ray->angle > 270 || ray->angle < 90)
	{
		ray->len_x = fabs(((int)ray->org_x + 1 - ray->org_x) / cos(ray->angle_r));
		ray->map_x = ray->org_x + ray->len_x;
	}
	if (ray->angle < 180 && ray->angle > 0)
	{
		ray->len_y = fabs((ray->org_y - (int)ray->org_y) / sin(ray->angle_r));
		ray->map_y = ray->org_y - ray->len_y;
	}
	if (ray->angle > 180 && ray->angle < 360)
	{
		ray->len_y = fabs(((int)ray->org_y + 1 - ray->org_y) / sin(ray->angle_r));
		ray->map_y = ray->org_y + ray->len_y;
	}
}

int		ray_check_hit(void)
{
	return (0);
}

int		ray_check_outside(void)
{
	return (0);
}

void	ray_calc_steps(t_ray *ray)
{
	//int out_hit;

	//out_hit = 0;
	set_steps_x_y(ray);
	calc_init_distance(ray);

	while (ray_check_hit() == 0)
	{
		if (ray_check_outside() == 0)
			return ;
	}

}

void	*init_ray(t_ray **ray, double angle, double org_x, double org_y)
{
	*ray = malloc(sizeof(t_ray));
	if (!(*ray))
		return ((void *)1);
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
	t_ray *ray;
	double angle;
	(void)cubed;

	ray = NULL;
	angle = 45;

	if (init_ray(&ray, angle, 0.5, 3.5) != 0)
		return (MALL_ERR);
	ray_calc_steps(ray);

	printf("ray angle: %f \n", ray->angle);
	printf("ray step_x: %d \n", ray->step_x);
	printf("ray step_y: %d \n", ray->step_y);
	printf("ray org_x: %f \n", ray->org_x);
	printf("ray org_y: %f \n", ray->org_y);
	printf("ray len_x: %f \n", ray->len_x);
	printf("ray len_y: %f \n", ray->len_y);
	printf("ray map_x: %f \n", ray->map_x);
	printf("ray map_y: %f \n", ray->map_y);

	free(ray);
	return (0);
}
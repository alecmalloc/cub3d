#include "cubed.h"


int		init_ray(t_ray **ray, double angle, double org_x, double org_y)
{
	*ray = malloc(sizeof(t_ray));
	if (!(*ray))
		return (MALL_ERR);
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
	(*ray)->delta_x = fabs(1 / (cos((*ray)->angle_r)));
	(*ray)->delta_y = fabs(1 / (sin((*ray)->angle_r)));
	return (0);
}

int		init_spread_rays(t_cubed *cubed, double angle, double pos_x, double pos_y)
{
	int i;
	double fov;
	int num_rays;
	int ray_angle;
	double angle_col;
	double start_angle;
	t_ray *ray;

	fov = 90;
	num_rays = 100;
	i = num_rays;
	angle_col = fov / num_rays;
	start_angle = angle + ((((num_rays + 1) / 2) - 1) * angle_col);

	while (i)
	{
		// printf("RAY NUM: %d\n", (num_rays - i));

		ray_angle = ((start_angle) - (angle_col * (num_rays - i)));
		if (ray_angle < 0)
			ray_angle += 360;
		
		if (init_ray(&ray, ray_angle, pos_x, pos_y) == MALL_ERR)
			return (MALL_ERR);
		ray_calc_steps(cubed, ray);
		free(ray);
		i--;
		printf("---------------------\n");
	}
	return (0);
}
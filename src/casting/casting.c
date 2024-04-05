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

void	calc_init_distance_x(t_ray *ray)
{
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
	}

	// if (ray->hit == HIT_WALL)
	printf("hit wall x: %f y: %f\n", ray->map_x, ray->map_y);

	if (ray->hit != HIT_WALL)
		min_len = -1;
	else if (ray->len_x < ray->len_y)
		min_len = ray->len_x;
	else
		min_len = ray->len_y;
	
	// printf("c len_x: %f\n", ray->len_x);
	// printf("c len_y: %f\n", ray->len_y);
	printf("ray min dist: %f\n", min_len);

	// double corr_dist = min_len * cos(ray->angle_r - conv_deg_rad(cubed->game->dir));
	// printf("CORR DIST: %f\n", corr_dist);
}

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

	fov = 120;
	num_rays = 11;
	i = num_rays;
	angle_col = fov / num_rays;
	start_angle = angle + ((((num_rays + 1) / 2) - 1) * angle_col);

	while (i)
	{
		printf("RAY NUM: %d\n", (num_rays - i));

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
	// if (init_ray(&ray, 126.363636, 12.5, 3.5) != 0)
	// 	return (MALL_ERR);
	// ray_calc_steps(cubed, ray);
	// free(ray);

	return (0);
}
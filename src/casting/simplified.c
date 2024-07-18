/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplified.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:49:25 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/18 11:23:53 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
/*
void	dda(t_casting *cast)
{
	//perform DDA
	int hit = 0;
	while (hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (cast->side_dist_x < cast->side_dist_y)
		{
			cast->side_dist_x += cast->delta_dist_x;
			cast->map_x += cast->step_x;
			cast->side = 0;
		}
		else
		{
			cast->side_dist_y += cast->delta_dist_y;
			cast->map_y += cast->step_y;
			cast->side = 1;
		}
		if (cast->map[cast->map_y][cast->map_x] == '1') hit = 1;
		//if (hit == 1)
			printf("Wall hit, x, y: %d, %d\n", cast->map_x, cast->map_y);
	}
}

void	declare_ray_vars(t_casting *cast, t_cubed *master)
{
	cast->camera_x = 2 * cast->x / (double)cast->screen_w - 1;
	cast->ray_dir_x = master->game->dir_x + cast->plane_x * cast->camera_x;
	cast->ray_dir_y = master->game->dir_y + cast->plane_y * cast->camera_x;

	cast->map_x = (int)cast->pos_x;
	cast->map_y = (int)cast->pos_y;

	cast->delta_dist_x = (cast->ray_dir_x == 0) ? 1e30 : fabs(1 / cast->ray_dir_x);
	cast->delta_dist_y = (cast->ray_dir_y == 0) ? 1e30 : fabs(1 / cast->ray_dir_y);
}

void	init_ray_dir(t_casting *cast)
{
	if (cast->ray_dir_x < 0)
		{
			cast->step_x = -1;
			cast->side_dist_x = (cast->pos_x - cast->map_x) * cast->delta_dist_x;
		}
		else
		{
			cast->step_x = 1;
			cast->side_dist_x = (cast->map_x + 1.0 - cast->pos_x) * cast->delta_dist_x;
		}
		if (cast->ray_dir_y < 0)
		{
			cast->step_y = -1;
			cast->side_dist_y = (cast->pos_y - cast->map_y) * cast->delta_dist_y;
		}
		else
		{
			cast->step_y = 1;
			cast->side_dist_y = (cast->map_y + 1.0 - cast->pos_y) * cast->delta_dist_y;
		}
}

void	draw_rays(t_casting *cast, t_cubed *master)
{
	// we iterate over every stripe of the screen and calculate the length of the line we need to draw
	cast->x = -1;
	while (cast->x++ < WIDTH)
	{
		declare_ray_vars(cast, master);
		init_ray_dir(cast);
		dda(cast);
		put_rays(cast->x, cast, master);
    	// verLine(x, draw_start, draw_end);
	}
}



void	simple_caster(t_cubed *cubed)
{
	t_casting cast;

	// load inits from map parser
	cast.map = cubed->parser->map->map;
	cast.pos_x = cubed->game->pos[0];
	cast.pos_y = cubed->game->pos[1];

	// test different angles here 90 and 270 are easy to test
	// keep in mind that 1 perpdistance is expected for 270 (because starts at stop of box)
	// 3 is expected perpdistance of 90 (because starts at top of box)
	// calculates distance from left to right of camera plane
	// camera plane is rotated when its 270 -> so then goes right to left
	// ./cub3D files_cub/test.cub > output.txt to see output better
	//
	cast.angle_d = cubed->game->dir;
	cast.angle_r = conv_deg_rad(cast.angle_d);
	cast.dir_x = cos(cast.angle_r);
	cast.dir_y = -sin(cast.angle_r);

	// set field of view and plane length and screen inits
	cast.fov = 66 * M_PI / 180;
	cast.plane_len = tan(cast.fov / 2);
	cast.plane_x = (-1 * cubed->game->dir_x) * cast.plane_len;
	cast.plane_y = cubed->game->dir_x * cast.plane_len;
	cast.screen_w = WIDTH;
	cast.screen_h = HIGHT;

	draw_rays(&cast, cubed);
	
}*/

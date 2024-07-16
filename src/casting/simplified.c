#include "cubed.h"

void	declare_ray_vars(t_casting *cast)
{
	cast->camera_x = 2 * x / (double)cast->screen_w - 1;
	cast->ray_dir_x = cast->dir_x + cast->plane_x * cast->camera_x;
	cast->ray_dir_y = cast->dir_y + cast->plane_y * cast->camera_x;

	cast->map_x = (int)cast->pos_x;
	cast->map_y = (int)cast->pos_y;

	cast->side_dist_x;
	cast->side_dist_y;
	cast->delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
	cast->delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);

	cast->step_x;
	cast->step_y;

	cast->hit = 0; //was there a wall hit?
	cast->side; //was a NS or a EW wall hit?
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

void	cast_rays(t_casting *cast, )
{
	// we iterate over every stripe of the screen and calculate the length of the line we need to draw
	int x = -1;
	while (x++ < cast->screen_w)
	{
		
		declare_ray_vars(cast);
		init_ray_dir(cast)

		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			//Check if ray has hit a wall


			if (map[map_y][map_x] == '1') hit = 1;
			if (hit)
				printf("hit wall at: %d %d\n", map_x, map_y);
		}

		double perp_wall_dist;
		if(side == 0) perp_wall_dist = (side_dist_x - delta_dist_x);
      	else          perp_wall_dist = (side_dist_y - delta_dist_y);

		//Calculate height of line to draw on screen
		int line_height = (int)(screen_h / perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		int draw_start = -line_height / 2 + screen_h / 2;
		if(draw_start < 0)draw_start = 0;
		int draw_end = line_height / 2 + screen_h / 2;
		if(draw_end >= screen_h)draw_end = screen_h - 1;
		printf("Ray %d: pos(%.3f, %.3f) map(%d, %d)\n", x, pos_x, pos_y, map_x, map_y);
		printf("  rayDir(%.3f, %.3f) deltaDist(%.3f, %.3f)\n", ray_dir_x, ray_dir_y, delta_dist_x, delta_dist_y);
		printf("  step(%d, %d) sideDist(%.3f, %.3f)\n", step_x, step_y, side_dist_x, side_dist_y);
		printf("  perp_wall_dist: %.3f side: %d\n", perp_wall_dist, side);
	}
}



void	simple_caster(t_cubed *cubed)
{
	t_casting cast;
	cast.map = cubed->parser->map->map;
	cast.pos_x = cubed->game->pos[0];
	cast.pos_y = cubed->game->pos[1];
	cast.angle_d = 270;
	cast.angle_r = conv_deg_rad(cast.angle_d);
	cast.dir_x = cos(cast.angle_r);
	cast.dir_y = -sin(cast.angle_r);

	printf("dir_x: %f dir_y: %f\n", cast.dir_x, cast.dir_y);
	cast.fov = 66 * M_PI / 180;
	cast.plane_len = tan(cast.fov / 2);

	cast.plane_x = (-1 * cast.dir_y) * cast.plane_len;
	cast.plane_y = cast.dir_x * cast.plane_len;

	cast.screen_w = 640;
	cast.screen_h = 480;

	cast_rays(&cast, 640, 480);

	//draw the pixels of the stripe as a vertical line
    // verLine(x, draw_start, draw_end);
}
#include "cubed.h"

void	simple_caster(t_cubed *cubed)
{
	char ** map = cubed->parser->map->map;
	double pos_x = cubed->game->pos[1];
	double pos_y = cubed->game->pos[0];
	double angle_d = cubed->game->dir;
	double angle_r = conv_deg_rad(angle_d);
	double dir_x = cos(angle_r);
	double dir_y = sin(angle_r);

	double fov = 66 * M_PI / 180;
	double plane_len = tan(fov / 2);

	double plane_x = -dir_y * plane_len;
	double plane_y = dir_x * plane_len;

	int screen_w = 640;
	int screen_h = 480;
	int x = -1;
	while (x++ < screen_w)
	{
		double camera_x = 2 * x / (double)screen_w - 1;
		double ray_dir_x = dir_x + plane_x * camera_x;
		double ray_dir_y = dir_y + plane_y * camera_x;

		int map_x = (int)pos_x;
		int map_y = (int)pos_y;

		double side_dist_x;
      	double side_dist_y;
		double delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
      	double delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);

		int step_x;
      	int step_y;

		int hit = 0; //was there a wall hit?
      	int side; //was a NS or a EW wall hit?

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
		}

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
			printf("map_x: %d, map_y: %d\n", map_x, map_y);
			printf("pos_x: %f, pos_y: %f\n", pos_x, pos_y);


			if (map[map_x][map_y] == '1') hit = 1;
		}

		double perpWallDist;
		if(side == 0) perpWallDist = (side_dist_x - delta_dist_x);
      	else          perpWallDist = (side_dist_y - delta_dist_y);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(screen_h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screen_h / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + screen_h / 2;
		if(drawEnd >= screen_h)drawEnd = screen_h - 1;
		printf("Ray %d: pos(%.3f, %.3f) map(%d, %d)\n", x, pos_x, pos_y, map_x, map_y);
		printf("  rayDir(%.3f, %.3f) deltaDist(%.3f, %.3f)\n", ray_dir_x, ray_dir_y, delta_dist_x, delta_dist_y);
		printf("  step(%d, %d) sideDist(%.3f, %.3f)\n", step_x, step_y, side_dist_x, side_dist_y);
		printf("  perpWallDist: %.3f side: %d\n", perpWallDist, side);
	}
}
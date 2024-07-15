#include "cubed.h"

void	simple_caster(t_cubed *cubed)
{
	char ** map = cubed->parser->map->map;
	double pos_x = cubed->game->pos[0];
	double pos_y = cubed->game->pos[1];
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
		double rayDirX = dir_x + plane_x * camera_x;
		double rayDirY = dir_y + plane_y * camera_x;

		int mapX = (int)pos_x;
		int mapY = (int)pos_y;

		double sideDist_x;
      	double sideDist_y;
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      	double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		int stepX;
      	int stepY;

		int hit = 0; //was there a wall hit?
      	int side; //was a NS or a EW wall hit?


		if (rayDirX < 0)
		{
			stepX = -1;
			sideDist_x = (pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDist_x = (mapX + 1.0 - pos_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDist_y = (pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDist_y = (mapY + 1.0 - pos_y) * deltaDistY;
		}

		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDist_x < sideDist_y)
			{
				sideDist_x += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDist_y += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (map[mapX][mapY] > 0) hit = 1;
		}

		double perpWallDist;
		if(side == 0) perpWallDist = (sideDist_x - deltaDistX);
      	else          perpWallDist = (sideDist_y - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(screen_h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screen_h / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + screen_h / 2;
		if(drawEnd >= screen_h)drawEnd = screen_h - 1;
		printf("perpwall = %f", perpWallDist);
	}
}
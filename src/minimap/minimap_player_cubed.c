#include "cubed.h"

void	calc_end(int cx, int cy, int *ex, int *ey, t_cubed *master)
{
	double	radius;
	int	standart;

	standart = ((int)master->game->dir - 90);
	if (standart >= 360)
		standart = standart - 360;
	radius = standart * M_PI / 180;
	*ex = cx + (MINI_SIZE * 2 * cos(radius));
	*ey = cy + (MINI_SIZE * 2 * sin(radius));
}

void	draw_line(int cx, int cy, int ex, int ey, mlx_image_t *img)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	tmp;
	int	tmp2; 

	dx = abs(ex - cx);
	dy = abs(ey - cy);
	if (cx < ex)
		sx = 1;
	else 
		sx = -1;
	if (cy < ey)
		sy = 1;
	else
		sy = -1;
	tmp = dx - dy;
	while (cx != ex || cy != ey)
	{
		put_pixel_cubed(img, cx, cy, 0xFF0000FF);
		tmp2 = 2 * tmp;
		if (tmp2 > -dy)
		{
			tmp -= dy;
			cx += sx;
		}
		if (tmp2 < dx)
		{
			tmp += dx;
			cy += sy;
		}
	}
}

void	draw_player(int x, int y, mlx_image_t *img, t_cubed *master)
{
	int	center_x;
	int	center_y;
	int	end_x;
	int	end_y;

	center_x = x - master->map->size / 2;
	center_y = y - master->map->size / 2;
	calc_end(center_x, center_y, &end_x, &end_y, master);
	draw_line(center_x, center_y, end_x, end_y, img);
}

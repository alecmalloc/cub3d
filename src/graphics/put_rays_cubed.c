#include "cubed.h"

static void	set_vars(t_casting *cast, t_cubed *master)
{
	if (cast->side == 0)
		master->draw->dist_to_wall = (cast->side_dist_x - cast->delta_dist_x);
	else
		master->draw->dist_to_wall = (cast->side_dist_y - cast->delta_dist_y);
	master->draw->line_height = (int)(HIGHT / master->draw->dist_to_wall);
	//changed from -master->.../ 2 + hight ...
	master->draw->start_drawing = -master->draw->line_height / 2 + HIGHT / 2;
	if (master->draw->start_drawing < 0)
		master->draw->start_drawing = 0;
	master->draw->end_drawing = (HIGHT / 2) + (master->draw->line_height / 2);
	if (master->draw->end_drawing >= HIGHT)
		master->draw->end_drawing = HIGHT - 1;
	if (cast->side && (cast->angle_d > 270 || cast->angle_d < 90))
		master->draw->tex = EAST;
	else
		master->draw->tex = WEST;
	if (!cast->side && cast->angle_d < 180)
		master->draw->tex = NORTH;
	else
		master->draw->tex = SOUTH;
}

static void	calc_vars(t_cubed *master, t_casting *cast, double *wallx, double *step, double *texpos, int *texx)
{
	
	if (!cast->side)
		*wallx = master->game->pos[0] + master->draw->dist_to_wall * cast->\
			 ray_dir_y;
	else
		*wallx = master->game->pos[1] + master->draw->dist_to_wall * cast->\
			 ray_dir_x;
	*wallx -= floor(*wallx);
	*texx = (int)(*wallx * (double)master->tex->img[master->draw->tex]->width);
	if (cast->side == 0 && cast->ray_dir_x > 0)
		*texx = master->tex->img[master->draw->tex]->width - *texx - 1;
	if (cast->side == 1 && cast->ray_dir_y < 0)
		*texx = master->tex->img[master->draw->tex]->width - *texx - 1;
	*step = 1.0 * master->tex->img[master->draw->tex]->height / master->draw->line_height;
	*texpos = (master->draw->start_drawing - HIGHT / 2 + master->draw->line_height / 2) * *step;
}

static uint32_t	get_color_tex(mlx_image_t *img, int x, int y)
{
	uint8_t	*pixel;	
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	pixel = &img->pixels[((y * img->width) + x) * 4];
	r = pixel[0];
	g = pixel[1];
	b = pixel[2];
	a = pixel[3];
	return (r << 24 | g << 16 | b << 8 | a);
}

void	put_rays(int x, t_casting *cast, t_cubed *master)
{
	double		wallx;
	double		step;
	double		texpos;
	int		texx;
	int		texy;
	int		y;
	uint32_t	color;

	set_vars(cast, master);
	calc_vars(master, cast, &wallx, &step, &texpos, &texx);
	y = master->draw->start_drawing;
	while (y < master->draw->end_drawing)
	{
		texy = (int)texpos & (master->tex->img[master->draw->tex]->height - 1);
		texpos += step;
		color = get_color_tex(master->tex->img[master->draw->tex], texx, texy);
		master->draw->draw_buffer[x][y] = color;
		y++;
	}
}

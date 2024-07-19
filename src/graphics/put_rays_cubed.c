/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rays_cubed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:03:11 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:03:12 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	set_vars(t_casting *caster, t_cubed *master)
{
	if (caster->side == 0)
		master->draw->dist_to_wall = (caster->map_x - master->game->pos[0] + \
				(1 - caster->step_x) / 2) / caster->ray_dir_x;
	else
		master->draw->dist_to_wall = (caster->map_y - master->game->pos[1] + \
				(1 - caster->step_y) / 2) / caster->ray_dir_y;
	master->draw->line_height = (int)(HIGHT / master->draw->dist_to_wall);
	master->draw->start_drawing = -master->draw->line_height / 2 + HIGHT / 2;
	if (master->draw->start_drawing < 0)
		master->draw->start_drawing = 0;
	master->draw->end_drawing = (HIGHT / 2) + (master->draw->line_height / 2);
	if (master->draw->end_drawing >= HIGHT)
		master->draw->end_drawing = HIGHT - 1;
	if (caster->side && (master->game->dir_x >= 0))
		master->draw->tex = EAST;
	else
		master->draw->tex = WEST;
	if (!caster->side && master->game->dir_y < 0)
		master->draw->tex = NORTH;
	else
		master->draw->tex = SOUTH;
}

static void	calc_vars(t_cubed *master, t_casting *caster)
{
	if (caster->side == 0)
		master->draw->wallx = master->game->pos[1] \
			+ master->draw->dist_to_wall * caster->ray_dir_y;
	else
		master->draw->wallx = master->game->pos[0] \
			+ master->draw->dist_to_wall * caster->ray_dir_x;
	master->draw->wallx -= floor(master->draw->wallx);
	master->draw->texx = (int)(master->draw->wallx * \
			(double)master->tex->img[master->draw->tex]->width);
	if (caster->side == 0 && caster->ray_dir_x > 0)
		master->draw->texx = master->tex->img[master->draw->tex]->width \
					- master->draw->texx - 1;
	if (caster->side == 1 && caster->ray_dir_y < 0)
		master->draw->texx = master->tex->img[master->draw->tex]->width \
					- master->draw->texx - 1;
	master->draw->step = 1.0 * master->tex->img[master->draw->tex]->height \
					/ master->draw->line_height;
	master->draw->texpos = (master->draw->start_drawing - HIGHT / 2 \
			+ master->draw->line_height / 2) * master->draw->step;
}

static void	get_tex(t_casting *cast, t_cubed *master)
{
	if (cast->hit == '1')
	{
		if (!cast->side && (cast->ray_dir_x > 0))
			master->draw->tex = EAST;
		else if (!cast->side && (cast->ray_dir_x < 0))
			master->draw->tex = WEST;
		if (cast->side && (cast->ray_dir_y < 0))
			master->draw->tex = NORTH;
		else if (cast->side && (cast->ray_dir_y > 0))
			master->draw->tex = SOUTH;
	}
	else if (cast->hit == '2')
		master->draw->tex = DOOR;
	else if (cast->hit == '3')
		master->draw->tex = OPENDOOR;
	else if (cast->hit == '4')
		decide_sprite(master);
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
	uint32_t	color;
	int			y;

	set_vars(cast, master);
	calc_vars(master, cast);
	y = master->draw->start_drawing;
	get_tex(cast, master);
	while (y < master->draw->end_drawing)
	{
		master->draw->texy = (int)master->draw->texpos & \
			(master->tex->img[master->draw->tex]->height - 1);
		master->draw->texpos += master->draw->step;
		color = get_color_tex(master->tex->img[master->draw->tex], \
				master->draw->texx, master->draw->texy);
		master->draw->draw_buffer[x][y] = color;
		y++;
	}
}

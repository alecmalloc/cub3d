/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_cubed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:04:09 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:04:10 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	set_minimap(t_cubed *master)
{
	master->map->start_x = (int)(WIDTH * 0.05);
	master->map->start_y = (int)(WIDTH * 0.05);
	master->map->end_x = master->map->start_x * 2;
	master->map->end_y = master->map->start_y * 2;
	master->map->offset_x = master->map->start_x / 2;
	master->map->offset_y = master->map->start_y / 2;
	master->map->size = master->map->start_x / MINI_SIZE;
	master->map->cur_x = master->map->start_x;
	master->map->cur_y = master->map->start_y;
}

static uint32_t	get_color(int x, int y, t_cubed *master)
{
	if (x < 0 || y < 0)
		return (0xFFFFFFFF);
	else if (x >= master->parser->map->x_len || y >= master->parser->map->y_len)
		return (0xFFFFFFFF);
	else if ((int)master->game->map[y][x] == '1')
		return (0x000000FF);
	else if ((int)master->game->map[y][x] == '2' || \
			(int)master->game->map[y][x] == '3')
		return (0x003F3FFF);
	else if ((int)master->game->map[y][x] == '4')
		return (0x204060FF);
	if (x == (int)master->game->pos[0] && y == (int)master->game->pos[1])
		return (0xFF0000FF);
	return (0xFFFFFFFF);
}

static void	put_minimap(int x, int y, t_cubed *master)
{
	uint32_t	color;
	int			z_x;
	int			z_y;

	color = get_color(x, y, master);
	z_y = master->map->cur_y;
	while (z_y < master->map->cur_y + master->map->size)
	{
		z_x = master->map->cur_x;
		while (z_x < master->map->cur_x + master->map->size)
		{
			master->draw->draw_buffer[z_x][z_y] = color;
			z_x++;
		}
		z_y++;
	}
}

void	load_minimap(t_cubed *master)
{
	int	x;
	int	y;

	y = master->game->pos[1] - MINI_SIZE;
	while (y < master->game->pos[1] + MINI_SIZE)
	{
		x = master->game->pos[0] - MINI_SIZE;
		while (x < master->game->pos[0] + MINI_SIZE)
		{
			put_minimap(x, y, master);
			x++;
			master->map->cur_x += master->map->size;
		}
		y++;
		master->map->cur_y += master->map->size;
		master->map->cur_x = master->map->offset_x;
	}
	master->map->cur_x = master->map->offset_x;
	master->map->cur_y = master->map->offset_y;
}

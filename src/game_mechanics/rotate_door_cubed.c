/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_door_cubed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:02:52 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:02:53 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	rotate(int dir, t_cubed *master)
{
	double	tmp;

	tmp = master->game->dir_x;
	master->game->dir_x = master->game->dir_x * cos(ROTSPEED * dir) \
			- master->game->dir_y * sin(ROTSPEED * dir);
	master->game->dir_y = tmp * sin(ROTSPEED * dir) \
			+ master->game->dir_y * cos(ROTSPEED * dir);
	tmp = master->game->plane_x;
	master->game->plane_x = master->game->plane_x * \
			cos(ROTSPEED * dir) - master->game->plane_y * sin(ROTSPEED * dir);
	master->game->plane_y = tmp * sin(ROTSPEED * dir) \
			+ master->game->plane_y * cos(ROTSPEED * dir);
	return (1);
}

int	handle_door(t_cubed *master)
{
	char	door;
	int		x;
	int		y;

	x = master->game->pos[0] + master->game->dir_x;
	y = master->game->pos[1] + master->game->dir_y;
	door = master->game->map[y][x];
	if (door == '2' || door == '3')
	{
		if (door == '2')
			master->game->map[y][x] = '3';
		else if (door == '3')
			master->game->map[y][x] = '2';
		return (1);
	}
	return (0);
}

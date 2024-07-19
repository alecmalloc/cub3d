/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_cubed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:03:39 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:03:40 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	init_game(t_game **game)
{
	*game = (t_game *)malloc(sizeof(t_game));
	if (!*game)
		return (MALL_ERR);
	(*game)->w = 0;
	(*game)->a = 0;
	(*game)->s = 0;
	(*game)->d = 0;
	(*game)->l = 0;
	(*game)->r = 0;
	(*game)->space = 0;
	(*game)->dir_x = 0;
	(*game)->dir_y = 0;
	(*game)->pos[0] = 0;
	(*game)->pos[1] = 0;
	(*game)->map = NULL;
	return (0);
}

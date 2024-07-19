/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:03:42 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:03:43 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	init_minimap(t_cubed **master)
{
	(*master)->map = (t_minimap *)malloc(sizeof(t_minimap));
	if (!(*master)->map)
		return (MALL_ERR);
	(*master)->map->start_x = -1;
	(*master)->map->start_y = -1;
	(*master)->map->offset_x = -1;
	(*master)->map->offset_x = -1;
	(*master)->map->end_x = -1;
	(*master)->map->end_x = -1;
	return (0);
}

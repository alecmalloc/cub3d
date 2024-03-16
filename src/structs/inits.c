/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:19:35 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/16 17:28:56 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	*init_f_imgs(t_cubed *cubed)
{
	t_f_img	*floor;
	t_f_img	*ceiling;

	floor = malloc(sizeof(t_f_img));
	ceiling = malloc(sizeof(t_f_img));
	if (!floor || !ceiling)
		return (NULL);
	cubed->ceiling = ceiling;
	cubed->floor = floor;
	return ((void *)1);
}

void	*init_structs(t_cubed *cubed)
{
	if (init_f_imgs(cubed) == NULL)
		return (NULL);
	return ((void *)1);
}
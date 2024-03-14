/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backdrop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:20:20 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/14 17:05:13 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

#include <stdio.h>

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	fill_image_color(t_cubed *cubed, int color)
{
	int				bpp;
	unsigned int	i;
	unsigned int	px;

	i = -1;
	bpp = sizeof(int32_t);
	px = cubed->images->ceiling->width * cubed->images->ceiling->height;
	memset(cubed->images->ceiling->pixels, color, px * bpp);
}

void	set_ceiling_color(t_cubed *cubed)
{
	int	color;

	color = get_rgba(0, 0, 255, 1);
	printf("color-> %d\n", color);
	fill_image_color(cubed, color);
}

// create a ceiling and a floor -> get user input to do this
void	put_backdrop(t_cubed *cubed)
{
	cubed->images->ceiling = mlx_new_image(cubed->mlx_inst, 1500, 400);
	set_ceiling_color(cubed);
	mlx_image_to_window(cubed->mlx_inst, cubed->images->ceiling, 0, 0);
}

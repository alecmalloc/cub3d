/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backdrop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:20:20 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/16 13:56:53 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

// setting each color in its own channel, rgb(a) -> a is opacity 
void	fill_image_color(mlx_image_t *image, int r, int g, int b)
{
	int i;
	int px;
	int bpp;

	i = 0;
	bpp = sizeof(int32_t);
	px = image->width * image->height * bpp;
	while (i < px)
	{
		image->pixels[i] = r;
		image->pixels[i + 1] = g;
		image->pixels[i + 2] = b;
		image->pixels[i + 3] = 255;
		i += 4;
	}
}

// create a ceiling and a floor -> get user input to do this
void	put_backdrop(t_cubed *cubed)
{
	cubed->images->ceiling = mlx_new_image(cubed->mlx_inst, 1500, 400);
	cubed->images->floor = mlx_new_image(cubed->mlx_inst, 1500, 400);
	fill_image_color(cubed->images->ceiling, 0, 100, 100);
	fill_image_color(cubed->images->floor, 100, 9, 100);
	mlx_image_to_window(cubed->mlx_inst, cubed->images->ceiling, 0, 0);
	mlx_image_to_window(cubed->mlx_inst, cubed->images->floor, 0, 400);
}

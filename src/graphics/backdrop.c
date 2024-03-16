/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backdrop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:20:20 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/16 17:29:56 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

// setting each color in its own channel, rgb(a) -> a is opacity 
// need to make sure it runs on school computers, will probs condense and use int with specific bit number to make simpler
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
// the pixel amounts are abritrary values, just wanted to test filling images with color
void	put_backdrop(t_cubed *cubed)
{
	cubed->ceiling->image = mlx_new_image(cubed->mlx_inst, 1500, 400);
	cubed->floor->image = mlx_new_image(cubed->mlx_inst, 1500, 400);
	fill_image_color(cubed->ceiling->image, 0, 100, 100);
	fill_image_color(cubed->floor->image, 100, 9, 100);
	mlx_image_to_window(cubed->mlx_inst, cubed->ceiling->image, 0, 0);
	mlx_image_to_window(cubed->mlx_inst, cubed->floor->image, 0, 400);
}

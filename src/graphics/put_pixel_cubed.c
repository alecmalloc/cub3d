/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_cubed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:03:08 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:03:09 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	draw_pixel_cubed(uint8_t *pixel, uint32_t color)
{
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}

void	put_pixel_cubed(mlx_image_t *img, uint32_t x, uint32_t y, \
	uint32_t color)
{
	uint8_t	*pixelstart;

	if (img)
	{
		if (x < img->width && y < img->height)
		{
			pixelstart = &img->pixels[(y * img->width + x) * \
					sizeof(int32_t)];
			draw_pixel_cubed(pixelstart, color);
		}
	}
}

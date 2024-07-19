/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:03:06 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:03:07 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
//load the images to textures then image ptr to main struct

static void	print_image(mlx_image_t *new, t_cubed *master)
{
	int			z;
	int			z2;

	z = 0;
	z2 = 0;
	while (z < WIDTH)
	{
		z2 = 0;
		while (z2 < HIGHT)
		{
			put_pixel_cubed(new, z, z2, \
			master->draw->draw_buffer[z][z2]);
			z2++;
		}
		z++;
	}
}

int	make_image(t_cubed *master)
{
	mlx_image_t	*new;

	new = mlx_new_image(master->mlx_inst, WIDTH, HIGHT);
	if (!new)
		return (MLX_IMG_ERR);
	put_backdrop(master);
	caster(master);
	load_minimap(master);
	print_image(new, master);
	if (mlx_image_to_window(master->mlx_inst, new, 0, 0) < 0)
		return (MLX_IMG_ERR);
	if (master->tmp)
		mlx_delete_image(master->mlx_inst, master->tmp);
	master->tmp = new;
	return (0);
}

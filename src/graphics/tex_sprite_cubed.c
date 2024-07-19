/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_sprite_cubed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:03:17 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:03:18 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	tex_to_image_sprite_2(t_cubed *master)
{
	master->tex->img[12] = \
	mlx_texture_to_image(master->mlx_inst, master->tex->sp_texture[6]);
	if (!master->tex->img[12])
		return (LTSP_ERR);
	master->tex->img[13] = \
	mlx_texture_to_image(master->mlx_inst, master->tex->sp_texture[7]);
	if (!master->tex->img[13])
		return (LTSP_ERR);
	master->tex->img[14] = \
	mlx_texture_to_image(master->mlx_inst, master->tex->sp_texture[8]);
	if (!master->tex->img[14])
		return (LTSP_ERR);
	master->tex->img[15] = \
	mlx_texture_to_image(master->mlx_inst, master->tex->sp_texture[9]);
	if (!master->tex->img[15])
		return (LTSP_ERR);
	return (0);
}

static int	tex_to_image_sprite(t_cubed *master)
{
	master->tex->img[6] = \
	mlx_texture_to_image(master->mlx_inst, master->tex->sp_texture[0]);
	if (!master->tex->img[6])
		return (LTSP_ERR);
	master->tex->img[7] = \
	mlx_texture_to_image(master->mlx_inst, master->tex->sp_texture[1]);
	if (!master->tex->img[7])
		return (LTSP_ERR);
	master->tex->img[8] = \
	mlx_texture_to_image(master->mlx_inst, master->tex->sp_texture[2]);
	if (!master->tex->img[8])
		return (LTSP_ERR);
	master->tex->img[9] = \
	mlx_texture_to_image(master->mlx_inst, master->tex->sp_texture[3]);
	if (!master->tex->img[9])
		return (LTSP_ERR);
	master->tex->img[10] = \
	mlx_texture_to_image(master->mlx_inst, master->tex->sp_texture[4]);
	if (!master->tex->img[10])
		return (LTSP_ERR);
	master->tex->img[11] = \
	mlx_texture_to_image(master->mlx_inst, master->tex->sp_texture[5]);
	if (!master->tex->img[11])
		return (LTSP_ERR);
	return (tex_to_image_sprite_2(master));
}

static int	load_sprites_2(t_cubed *master)
{
	master->tex->sp_texture[5] = mlx_load_png(SPRITE6_TEX);
	if (!master->tex->sp_texture[5])
		return (LTSP_ERR);
	master->tex->sp_texture[6] = mlx_load_png(SPRITE7_TEX);
	if (!master->tex->sp_texture[6])
		return (LTSP_ERR);
	master->tex->sp_texture[7] = mlx_load_png(SPRITE8_TEX);
	if (!master->tex->sp_texture[7])
		return (LTSP_ERR);
	master->tex->sp_texture[8] = mlx_load_png(SPRITE9_TEX);
	if (!master->tex->sp_texture[8])
		return (LTSP_ERR);
	master->tex->sp_texture[9] = mlx_load_png(SPRITE10_TEX);
	if (!master->tex->sp_texture[9])
		return (LTSP_ERR);
	return (tex_to_image_sprite(master));
}

int	load_sprites(t_cubed *master)
{
	master->tex->sp_texture[0] = mlx_load_png(SPRITE1_TEX);
	if (!master->tex->sp_texture[0])
		return (LTSP_ERR);
	master->tex->sp_texture[1] = mlx_load_png(SPRITE2_TEX);
	if (!master->tex->sp_texture[1])
		return (LTSP_ERR);
	master->tex->sp_texture[2] = mlx_load_png(SPRITE3_TEX);
	if (!master->tex->sp_texture[2])
		return (LTSP_ERR);
	master->tex->sp_texture[3] = mlx_load_png(SPRITE4_TEX);
	if (!master->tex->sp_texture[3])
		return (LTSP_ERR);
	master->tex->sp_texture[4] = mlx_load_png(SPRITE5_TEX);
	if (!master->tex->sp_texture[4])
		return (LTSP_ERR);
	return (load_sprites_2(master));
}

void	decide_sprite(t_cubed *master)
{
	master->draw->tex = (int)master->tex->spritenbr + 5;
	master->tex->spritenbr += master->tex->spritemove;
	if (master->tex->spritenbr >= 10)
		master->tex->spritemove = -0.001;
	if (master->tex->spritenbr <= 1)
		master->tex->spritemove = 0.001;
}

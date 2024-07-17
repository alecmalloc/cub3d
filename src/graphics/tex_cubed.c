#include "cubed.h"

static int	text_to_image(t_cubed *master)
{
	master->tex->img[NORTH] = mlx_texture_to_image(master->mlx_inst, master->tex->n_texture);
	if (!master->tex->img[NORTH])
		return (LTN_ERR);
	master->tex->img[EAST] = mlx_texture_to_image(master->mlx_inst, master->tex->e_texture);
	if (!master->tex->img[EAST])
		return (LTE_ERR);
	master->tex->img[SOUTH] = mlx_texture_to_image(master->mlx_inst, master->tex->s_texture);
	if (!master->tex->img[SOUTH])
		return (LTS_ERR);
	master->tex->img[WEST] = mlx_texture_to_image(master->mlx_inst, master->tex->w_texture);
	if (!master->tex->img[WEST])
		return (LTW_ERR);
	master->tex->img[DOOR] = mlx_texture_to_image(master->mlx_inst, master->tex->d_texture);
	if (!master->tex->img[DOOR])
		return (LTD_ERR);
	master->tex->img[SPRITE] = mlx_texture_to_image(master->mlx_inst, master->tex->sp_texture);
	if (!master->tex->img[SPRITE])
		return (LTSP_ERR);
	return (0);
}

int	load_textures(t_cubed *master)
{
	master->tex->n_texture = mlx_load_png(master->parser->grafics->ntex);
	if (!master->tex->n_texture)
		return (LTN_ERR);
	master->tex->e_texture = mlx_load_png(master->parser->grafics->etex);
	if (!master->tex->e_texture)
		return (LTE_ERR);
	master->tex->s_texture = mlx_load_png(master->parser->grafics->ntex);
	if (!master->tex->s_texture)
		return (LTS_ERR);
	master->tex->w_texture = mlx_load_png(master->parser->grafics->wtex);
	if (!master->tex->w_texture)
		return (LTW_ERR);
	master->tex->d_texture = mlx_load_png(DOOR_TEX);
	if (!master->tex->d_texture)
		return (LTD_ERR);
	master->tex->sp_texture = mlx_load_png(SPRITE_TEX);
	if (!master->tex->sp_texture)
		return (LTSP_ERR);
	return (text_to_image(master));
}




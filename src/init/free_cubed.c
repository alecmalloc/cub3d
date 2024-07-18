#include "cubed.h"

void	free_tex_1(t_tex **tex)
{
	int	z;

	z = -1;
	while (++z < 10)
	{
		if ((*tex)->sp_texture[z])
			mlx_delete_texture((*tex)->sp_texture[z]);
	}
	if ((*tex)->n_texture)
		mlx_delete_texture((*tex)->n_texture);
	if ((*tex)->s_texture)
		mlx_delete_texture((*tex)->s_texture);
	if ((*tex)->e_texture)
		mlx_delete_texture((*tex)->e_texture);
	if ((*tex)->w_texture)
		mlx_delete_texture((*tex)->w_texture);
	if ((*tex)->d_texture)
		mlx_delete_texture((*tex)->d_texture);
	if ((*tex)->od_texture)
		mlx_delete_texture((*tex)->od_texture);
}

void	free_tex(t_cubed **cubed, t_tex **tex)
{
	int	z;

	z = -1;
	while (++z < 16)
	{
		if ((*tex)->img[z])
			mlx_delete_image((*cubed)->mlx_inst, (*tex)->img[z]);
	}
	free_tex_1(tex);
	free((*tex));
}

void	free_all(t_cubed **cubed)
{
	if ((*cubed)->parser)
		free_parser(&(*cubed)->parser);
	if ((*cubed)->tex)
		free_tex(cubed, &(*cubed)->tex);
	if ((*cubed)->game)
		free((*cubed)->game);
	if ((*cubed)->casting)
		free((*cubed)->casting);
	if ((*cubed)->map)
		free((*cubed)->map);
	if ((*cubed)->draw)
		free((*cubed)->draw);
	if ((*cubed)->mlx_inst)
	{
		mlx_close_window((*cubed)->mlx_inst);
		mlx_terminate((*cubed)->mlx_inst);
	}
	free(*cubed);
}

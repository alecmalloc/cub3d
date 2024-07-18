#include "cubed.h"

void	free_casting(t_cubed **cubed)
{
	// free sub elements
	free((*cubed)->casting);
}

void	free_draw(t_draw **draw)
{
	free(*draw);	
}

void	free_tex(t_cubed **cubed, t_tex **tex)
{
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
        if ((*tex)->sp_texture)
		mlx_delete_texture((*tex)->sp_texture);
	if ((*tex)->img[NORTH])
		mlx_delete_image((*cubed)->mlx_inst, (*tex)->img[NORTH]);
	if ((*tex)->img[EAST])
		mlx_delete_image((*cubed)->mlx_inst, (*tex)->img[EAST]);
	if ((*tex)->img[SOUTH])
		mlx_delete_image((*cubed)->mlx_inst, (*tex)->img[SOUTH]);
	if ((*tex)->img[WEST])
		mlx_delete_image((*cubed)->mlx_inst, (*tex)->img[WEST]);
	if ((*tex)->img[DOOR])
		mlx_delete_image((*cubed)->mlx_inst, (*tex)->img[DOOR]);
	if ((*tex)->img[OPENDOOR])
		mlx_delete_image((*cubed)->mlx_inst, (*tex)->img[OPENDOOR]);
	if ((*tex)->img[SPRITE])
		mlx_delete_image((*cubed)->mlx_inst, (*tex)->img[SPRITE]);
	free((*tex));
}

void	free_all(t_cubed **cubed)
{
	if ((*cubed)->parser)
		free_parser(&(*cubed)->parser);
	if ((*cubed)->tex)
		free_tex(cubed, &(*cubed)->tex);
	if ((*cubed)->game)
		free_game(&(*cubed)->game);
	if ((*cubed)->casting)
		free_casting(cubed);
	if ((*cubed)->map)
		free_minimap(&(*cubed)->map);
	if ((*cubed)->draw)
		free_draw(&(*cubed)->draw);
	if ((*cubed)->mlx_inst)
	{
		mlx_close_window((*cubed)->mlx_inst);
		mlx_terminate((*cubed)->mlx_inst);
	}
		
	free(*cubed);
}

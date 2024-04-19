#include "cubed.h"

void	free_f_imgs(t_cubed **cubed)
{
	if ((*cubed)->ceiling)
		free((*cubed)->ceiling);
	if ((*cubed)->floor)
		free((*cubed)->floor);
}

void	free_casting(t_cubed **cubed)
{
	// free sub elements
	free((*cubed)->casting);
}

void	free_tex(t_tex **tex)
{
	if ((*tex)->nw)
		mlx_delete_xpm42((*tex)->nw);
	if ((*tex)->ew)
		mlx_delete_xpm42((*tex)->ew);
	if ((*tex)->sw)
		mlx_delete_xpm42((*tex)->sw);
	if ((*tex)->ww)
		mlx_delete_xpm42((*tex)->ww);
	if ((*tex)->d)
		mlx_delete_xpm42((*tex)->d);
	if ((*tex)->s)
		mlx_delete_xpm42((*tex)->s);
	free((*tex));
}

void	free_all(t_cubed **cubed)
{
	if ((*cubed)->parser)
		free_parser(&(*cubed)->parser);
	if ((*cubed)->game)
		free_game(&(*cubed)->game);
	if ((*cubed)->casting)
		free_casting(cubed);
	if ((*cubed)->map)
		free_minimap(&(*cubed)->map);
	if ((*cubed)->tex)
		free_tex(&(*cubed)->tex);
	free_f_imgs(cubed);
	free(*cubed);
}

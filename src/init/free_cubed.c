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
	free_f_imgs(cubed);
	free(*cubed);
}

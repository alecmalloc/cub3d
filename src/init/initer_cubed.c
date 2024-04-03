#include "cubed.h"

static int	init_cubed(t_cubed **cubed)
{
	*cubed = (t_cubed *)malloc(sizeof(t_cubed));
	if (!cubed)
		return (MALL_ERR);
	(*cubed)->parser = NULL;
	(*cubed)->game = NULL;
	return (0);
}

static int	init_f_imgs(t_cubed **cubed)
{
	t_f_img	*floor;
	t_f_img	*ceiling;

	floor = malloc(sizeof(t_f_img));
	ceiling = malloc(sizeof(t_f_img));
	if (!floor || !ceiling)
		return (MALL_ERR);
	floor->image = NULL;
	floor->r = 0;
	floor->g = 0;
	floor->b = 0;
	ceiling->image = NULL;
	ceiling->r = 0;
	ceiling->g = 0;
	ceiling->b = 0;
	(*cubed)->ceiling = ceiling;
	(*cubed)->floor = floor;
	return (0);
}

int	init_casting(t_cubed **cubed)
{
	t_casting *casting;
	casting = malloc(sizeof(t_casting));
	if (!casting)
		return (MALL_ERR);
	casting->resolution_w = 800.0;
	(*cubed)->casting = casting;
	return (0);
}

int	init_all(t_cubed **cubed)
{
	if (init_cubed(cubed))
		return (MALL_ERR);
	if (init_f_imgs(cubed))
		return (MALL_ERR);
	if (init_parser(&(*cubed)->parser))
		return (MALL_ERR);
	if (init_game(&(*cubed)->game))
		return (MALL_ERR);
	if (init_casting(cubed))
		return (MALL_ERR);
	return (0);
}

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
	free_f_imgs(cubed);
	free(*cubed);
}

#include "cubed.h"

static int	init_cubed(t_cubed **cubed)
{
	*cubed = (t_cubed *)malloc(sizeof(t_cubed));
	if (!cubed)
		return (MALL_ERR);
	(*cubed)->parser = NULL;
	(*cubed)->game = NULL;
	(*cubed)->mlx_inst = NULL;
	(*cubed)->map = NULL;
	(*cubed)->tex = NULL;
	(*cubed)->casting = NULL;
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
	t_casting	*casting;

	casting = malloc(sizeof(t_casting));
	if (!casting)
		return (MALL_ERR);
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
	if (init_minimap(cubed))
		return (MALL_ERR);
	if (init_tex(cubed))
		return (MALL_ERR);
	return (0);
}

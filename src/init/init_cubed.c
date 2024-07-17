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
	(*cubed)->draw = NULL;
	return (0);
}

static int	init_casting(t_cubed **cubed)
{
	t_casting	*casting;

	casting = malloc(sizeof(t_casting));
	if (!casting)
		return (MALL_ERR);
	(*cubed)->casting = casting;
	return (0);
}

static int	init_draw(t_cubed **cubed)
{
	t_draw	*draw;
	int	z;
	int	z2;

	draw = (t_draw *)malloc(sizeof(t_draw));
	if (!draw)
		return (MALL_ERR);
	draw->dist_to_wall = -1;
	draw->line_height = -1;
	draw->start_drawing = -1;
	draw->end_drawing = -1;
	z = 0;
	z2 = 0;
	while (z < HIGHT)
	{
		while (z2 < WIDTH)
		{
			draw->draw_buffer[z][z2] = 0;
			z2++;
		}
		z++;
	}
	(*cubed)->draw = draw;
	return (0);
}
int	init_all(t_cubed **cubed)
{
	if (init_cubed(cubed))
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
	if (init_draw(cubed))
		return (MALL_ERR);
	return (0);
}

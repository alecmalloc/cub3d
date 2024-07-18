#include "cubed.h"

int	init_tex(t_cubed **cubed)
{
	(*cubed)->tex = (t_tex *)malloc(sizeof(t_tex));
	if (!(*cubed)->tex)
		return (MALL_ERR);
        (*cubed)->tex->n_texture = NULL;
        (*cubed)->tex->s_texture = NULL;
        (*cubed)->tex->e_texture = NULL;
        (*cubed)->tex->w_texture = NULL;
        (*cubed)->tex->d_texture = NULL;
        (*cubed)->tex->od_texture = NULL;
        (*cubed)->tex->sp_texture = NULL;
	(*cubed)->tex->img[NORTH] = NULL;
	(*cubed)->tex->img[EAST] = NULL;
	(*cubed)->tex->img[SOUTH] = NULL;
	(*cubed)->tex->img[WEST] = NULL;
	(*cubed)->tex->img[DOOR] = NULL;
	(*cubed)->tex->img[OPENDOOR] = NULL;
	(*cubed)->tex->img[SPRITE] = NULL;
	return (0);
}

#include "cubed.h"

int	init_tex(t_cubed **cubed)
{
	int	z;

	z = -1;
	(*cubed)->tex = (t_tex *)malloc(sizeof(t_tex));
	if (!(*cubed)->tex)
		return (MALL_ERR);
	(*cubed)->tex->n_texture = NULL;
	(*cubed)->tex->s_texture = NULL;
	(*cubed)->tex->e_texture = NULL;
	(*cubed)->tex->w_texture = NULL;
	(*cubed)->tex->d_texture = NULL;
	(*cubed)->tex->od_texture = NULL;
	(*cubed)->tex->spritenbr = 1.0;
	(*cubed)->tex->spritemove = 0.001;
	while (++z < 16)
		(*cubed)->tex->img[z] = NULL;
	z = -1;
	while (++z < 10)
		(*cubed)->tex->sp_texture[z] = NULL;
	return (0);
}

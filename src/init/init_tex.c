#include "cubed.h"

int	init_tex(t_cubed **cubed)
{
	(*cubed)->tex = (t_tex *)malloc(sizeof(t_tex));
	if (!(*cubed)->tex)
		return (MALL_ERR);
	(*cubed)->tex->nw = NULL;
	(*cubed)->tex->ew = NULL;
	(*cubed)->tex->sw = NULL;
	(*cubed)->tex->ww = NULL;
	(*cubed)->tex->d = NULL;
	(*cubed)->tex->s = NULL;
	return (0);
}

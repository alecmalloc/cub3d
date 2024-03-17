#include "cubed.h"

static int	init_cubed(t_cubed **cubed)
{
	*cubed = (t_cubed *)malloc(sizeof(t_cubed));
	if (!cubed)
		return(MALL_ERR);
	(*cubed)->ptr_mlx = NULL;
	(*cubed)->parser = NULL;
	return(0);
}

int	init_all(t_cubed **cubed)
{
	if (init_cubed(cubed))
		return(MALL_ERR);
	if (init_parser(&(*cubed)->parser))
		return(MALL_ERR);
	return(0);
}

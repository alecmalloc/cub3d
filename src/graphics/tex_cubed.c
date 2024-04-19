#include "cubed.h"

int	load_textures(t_cubed *master)
{
	master->tex->nw = mlx_load_xpm42(master->parser->grafics->ntex);
	if (!master->tex->nw)
		return (LTN_ERR);
	master->tex->ew = mlx_load_xpm42(master->parser->grafics->etex);
	if (!master->tex->ew)
		return (LTE_ERR);
	master->tex->sw = mlx_load_xpm42(master->parser->grafics->stex);
	if (!master->tex->sw)
		return (LTS_ERR);
	master->tex->ww = mlx_load_xpm42(master->parser->grafics->wtex);
	if (!master->tex->ww)
		return (LTW_ERR);
	master->tex->d = mlx_load_xpm42(DOOR_TEX);
	if (!master->tex->d)
		return (LTD_ERR);
	master->tex->s = mlx_load_xpm42(SPRITE_TEX);
	if (!master->tex->s)
		return (LTSP_ERR);
	return (0);
}

#include "cubed.h"

static int	init_grafics(t_graf **tmp)
{
	*tmp = (t_graf *)malloc(sizeof(t_graf));
	if (!*tmp)
		return (MALL_ERR);
	(*tmp)->ntex = NULL;
	(*tmp)->stex = NULL;
	(*tmp)->etex = NULL;
	(*tmp)->wtex = NULL;
	(*tmp)->fc[0] = -1;
	(*tmp)->fc[1] = -1;
	(*tmp)->fc[2] = -1;
	(*tmp)->sc[0] = -1;
	(*tmp)->sc[1] = -1;
	(*tmp)->sc[2] = -1;
	return (0);
}

static int	init_map(t_map **map)
{
	*map = (t_map *)malloc(sizeof(t_map));
	if (!*map)
		return (MALL_ERR);
	(*map)->x_len = 0;
	(*map)->y_len = 0;
	(*map)->map_storage = (char *)malloc(sizeof(char));
	if (!(*map)->map_storage)
		return (MALL_ERR);
	(*map)->map_storage[0] = '\0';
	(*map)->map = NULL;
	(*map)->player_dir = 0;
	(*map)->player_pos[0] = -1;
	(*map)->player_pos[1] = -1;
	return (0);
}

int	init_parser(t_parser **parser)
{
	*parser = (t_parser *)malloc(sizeof(t_parser));
	if (!*parser)
		return (MALL_ERR);
	(*parser)->grafics = NULL;
	(*parser)->map = NULL;
	(*parser)->fd = -1;
	if (init_grafics(&(*parser)->grafics))
		return (MALL_ERR);
	if (init_map(&(*parser)->map))
		return (MALL_ERR);
	return (0);
}

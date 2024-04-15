#include "cubed.h"

int	init_minimap(t_cubed **master)
{
	(*master)->map = (t_map *)malloc(sizeof(t_map));
	if (!(*master)->map)
		return (MALL_ERR);
	(*master)->map->start_x = -1;
	(*master)->map->start_y = -1;
	(*master)->map->end_x = -1;
	(*master)->map->end_x = -1;
}

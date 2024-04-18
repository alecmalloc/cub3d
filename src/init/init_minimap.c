#include "cubed.h"

int	init_minimap(t_cubed **master)
{
	(*master)->map = (t_minimap *)malloc(sizeof(t_minimap));
	if (!(*master)->map)
		return (MALL_ERR);
	(*master)->map->start_x = -1;
	(*master)->map->start_y = -1;
	(*master)->map->offset_x = -1;
	(*master)->map->offset_x = -1;
	return (0);
}

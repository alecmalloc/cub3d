#include "cubed.h"

void	set_minimap(t_cubed *master)
{
	master->map->start_x = (int)(WIDTH * 0.1);
	master->map->start_y = (int)(WIDTH * 0.1);
	master->map->end_x = master->map->start_x * 2;
	master->map->end_y = master->map->start_y * 2;
	master->map->cur_x = master->map->start_x;
	master->map->cur_y = master->map->start_y;
}

static void	put_minimap(int x, int y, t_cubed *master)
{
	
}

void	load_minimap(mlx_image_t *img, t_cubed *master)
{
	int	x;
	int	y;

	x = master->game->pos[1] - 10;
	y = master->game->pos[0] - 10;
	while (


}

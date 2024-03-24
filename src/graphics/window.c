#include "cubed.h"

// initialize mlx instance and load images
int	window_init(t_cubed	*cubed)
{
	cubed->mlx_inst = mlx_init(WIDTH, HIGHT, "cub3d", false);
	if (!(cubed->mlx_inst))
		return (MLXI_ERR);
	mlx_set_window_pos(cubed->mlx_inst, 210, 133);
	put_backdrop(cubed);
	return (0);
}

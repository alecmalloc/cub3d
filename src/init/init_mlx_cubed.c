#include "cubed.h"

int	init_window(t_cubed **cubed)
{
	(*cubed)->mlx_inst = mlx_init(WIDTH, HIGHT, "cub3d", false);
	if (!((*cubed)->mlx_inst))
		return (MLX_INIT_ERR);
	return (0);
}

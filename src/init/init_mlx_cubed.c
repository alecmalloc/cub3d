#include "cubed.h"

int	window_init(t_cubed **cubed)
{
	(*cubed)->mlx_inst = mlx_init(WIDTH, HIGHT "cub3d", false);
	if (!(cubed->mlx_inst))
		return (MLX_INIT_ERR);
	cubed->img = NULL;
	mlx_set_window_pos(cubed->mlx_inst, 210, 133);
}

#include "cubed.h"

// initialize mlx instance and load images
int	window_init(t_cubed	*cubed)
{
	cubed->mlx_inst = mlx_init(1500, 800, "cub3d", false);
	if (!(cubed->mlx_inst))
		return (EXIT_FAILURE);
	mlx_set_window_pos(cubed->mlx_inst, 210, 133);
	put_backdrop(cubed);
	mlx_loop(cubed->mlx_inst);
	mlx_terminate(cubed->mlx_inst);
	return (EXIT_SUCCESS);
}

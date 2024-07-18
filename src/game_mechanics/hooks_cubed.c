#include "cubed.h"

int	check_mouse(t_cubed *master)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(master->mlx_inst, &x, &y);
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HIGHT)
	{
		if (x < (WIDTH / 2) - (WIDTH / 8))
			rotate(-1, master);
		else if (x > (WIDTH / 2) + (WIDTH / 8))
			rotate(1, master);
		return (1);
	}
	return (0);
}

void	check_door(mlx_key_data_t key, void *tmp)
{
	t_cubed	*master;

	master = (t_cubed *)tmp;
	if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
		handle_door(master);
}

int	check_keys(t_cubed *master)
{
	if (mlx_is_key_down(master->mlx_inst, MLX_KEY_ESCAPE))
		exit_game(master);
	if (mlx_is_key_down(master->mlx_inst, MLX_KEY_W))
		return (move(0, master));
	if (mlx_is_key_down(master->mlx_inst, MLX_KEY_A))
		return (move(1, master));
	if (mlx_is_key_down(master->mlx_inst, MLX_KEY_S))
		return (move(2, master));
	if (mlx_is_key_down(master->mlx_inst, MLX_KEY_D))
		return (move(3, master));
	if (mlx_is_key_down(master->mlx_inst, MLX_KEY_LEFT))
		return (rotate(-1, master));
	if (mlx_is_key_down(master->mlx_inst, MLX_KEY_RIGHT))
		return (rotate(1, master));
	return (0);
}

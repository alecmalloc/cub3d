#include "cubed.h"

static void	set_game(t_cubed *master)
{
	master->game->dir = master->parser->map->player_dir;
	master->game->pos[0] = master->parser->map->player_pos[0];
	master->game->pos[1] = master->parser->map->player_pos[1];
	master->game->map = master->parser->map->map;
	mlx_set_cursor_mode(master->mlx_inst, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(master->mlx_inst, WIDTH / 2, HIGHT / 2);
}

void	exit_game(void *tmp)
{
	t_cubed	*master;

	master = (t_cubed *)tmp;
	mlx_close_window(master->mlx_inst);
	mlx_terminate(master->mlx_inst);
	free_all(&master);
	exit(0);
}

static void	loop_cubed(void *tmp)
{
	t_cubed	*master;

	master = (t_cubed *)tmp;
	check_mouse(master);
	check_keys(master);
}

int	start_game(t_cubed *master)
{
	set_game(master);
	printf("%f %f\n", master->game->pos[0], master->game->pos[1]);
	mlx_close_hook(master->mlx_inst, exit_game, master);
	mlx_key_hook(master->mlx_inst, check_door, master);
	mlx_loop_hook(master->mlx_inst, &loop_cubed, master);
	mlx_loop(master->mlx_inst);
	return (0);
}

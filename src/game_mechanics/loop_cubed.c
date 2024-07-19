#include "cubed.h"

static void	set_game(t_cubed *master)
{
	double	fov;
	double	plane_len;

	master->game->dir_x = master->parser->map->player_dir_x;
	master->game->dir_y = master->parser->map->player_dir_y;
	fov = 66.0 * M_PI / 180.0;
	plane_len = tan(fov / 2.0);
	master->game->plane_x = -master->game->dir_y * plane_len;
	master->game->plane_y = master->game->dir_x * plane_len;
	master->game->pos[0] = master->parser->map->player_pos[0] + 0.5;
	master->game->pos[1] = master->parser->map->player_pos[1] + 0.5;
	master->game->map = master->parser->map->map;
	master->game->map[(int)master->game->pos[1]] \
			[(int)master->game->pos[0]] = '0';
	mlx_set_mouse_pos(master->mlx_inst, WIDTH / 2, HIGHT / 2);
	set_minimap(master);
}

void	exit_game(void *tmp)
{
	t_cubed	*master;

	master = (t_cubed *)tmp;
	free_all(&master);
	exit(0);
}

static void	loop_cubed(void *tmp)
{
	t_cubed	*master;

	master = (t_cubed *)tmp;
	check_mouse(master);
	check_keys_move(master);
	check_keys_view(master);
	make_image(master);
}

int	start_game(t_cubed *master)
{
	int	ret;

	ret = init_window(&master);
	if (ret)
		return (ret);
	ret = load_textures(master);
	if (ret)
		return (ret);
	set_game(master);
	mlx_close_hook(master->mlx_inst, exit_game, master);
	mlx_key_hook(master->mlx_inst, check_door, master);
	mlx_loop_hook(master->mlx_inst, &loop_cubed, master);
	mlx_loop(master->mlx_inst);
	return (0);
}

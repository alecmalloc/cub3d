#include "cubed.h"

static void	set_game(t_cubed *master)
{
	master->game->dir = master->parser->map->player_dir;
	master->game->pos[0] = master->parser->map->player_pos[0];
	master->game->pos[1] = master->parser->map->player_pos[1];
	master->game->map = master->parser->map->map;
}

/*int	player_moved(t_cubed *master)
{
	if (master->game->w)
		return (move(master));
	if (master->game->a)
		return (move(master));
	if (master->game->s)
		return (move(master));
	if (master->game->d)
		return (move(master));
	if (master->game->l)
		return (rotate(master));
	if (master->game->r)
		return (rotate(master));
	if (master->game->space)
		return (interact_door(master));
	return (0);
}*/

static void	loop_cubed(void *tmp)
{
	t_cubed	*master;
	//player_moved((t_cubed *)master);
	master = (t_cubed *)tmp;
	move(master);
	//render
}

int	start_game(t_cubed *master)
{
	set_game(master);
	mlx_loop_hook(master->mlx_inst, &loop_cubed, master);
	mlx_loop(master->mlx_inst);
	return (0);
}

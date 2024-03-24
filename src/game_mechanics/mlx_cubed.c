#include "cubed.h"

static void	keypressed(mlx_key_data_t key, void *tmp)
{
	t_game	*game;

	game = (t_game *)tmp;
	if (key.key == W_KEY)
		game->w = 1;
	if (key.key == A_KEY)
		game->a = 1;
	else if (key.key == S_KEY)
		game->s = 1;
	else if	(key.key == D_KEY)
		game->d = 1;
	else if (key.key == SP_KEY)
		game->space = 1;
	else if (key.key == LEFT_KEY)
		game->l = 1;
	else if (key.key == RIGHT_KEY)
		game->r = 1;
}

static void	keyreleased(mlx_key_data_t key, void *tmp)
{
	t_game	*game;

	game = (t_game *)tmp;
	if (key.key == W_KEY)
		game->w = 0;
	if (key.key == A_KEY)
		game->a = 0;
	else if (key.key == S_KEY)
		game->s = 0;
	else if	(key.key == D_KEY)
		game->d = 0;
	else if (key.key == SP_KEY)
		game->space = 0;
	else if (key.key == LEFT_KEY)
		game->l = 0;
	else if (key.key == RIGHT_KEY)
		game->r = 0;
}

void	set_mlx(t_cubed *master)
{
	mlx_key_hook(master->mlx_inst, &keypressed, master->game);
	mlx_key_hook(master->mlx_inst, &keyreleased, master->game);
}

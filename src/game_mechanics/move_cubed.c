#include "cubed.h"

static int	get_dir(t_game *game, int rot)
{
	int	tmp;

	tmp = game->dir + rot;
	if (tmp > 360)
		tmp -= 360;
	if (tmp < 0)
		tmp = 360 - tmp;
	return (tmp);
}

static void	direction_top(double *x, double *y, int dir)
{
	if ((dir >= 337 && dir < 360) || (dir >= 0 && dir < 23))
		*y = 1;
	else if (dir >= 23 && dir < 68)
	{
		*x = 1;
		*y = 1;
	}
	else if (dir >= 68 && dir < 113)
		*x = 1;
	else if (dir >= 113 && dir < 158)
	{
		*x = 1;
		*y = -1;
	}
}

static void	direction_bottom(double *x, double *y, int dir)
{
	
	if (dir >= 158 && dir < 203)
		*y = -1;
	else if (dir >= 203 && dir < 248)
	{
		*x = -1;
		*y = -1;
	}
	else if (dir >= 248 && dir < 293)
		*x = -1;
	else if (dir >= 293 && dir < 337)
	{
		*x = -1;
		*y = 1;
	}
}

static void	get_direction_move(double *x, double *y, int dir, t_game *game)
{
	if (dir >= 337 || dir < 158)
		direction_top(x, y, dir);
	else
		direction_bottom(x, y, dir);
	*x = MOVESPEED * *x;
	*y = MOVESPEED * *y;
	if (*game->map[(int)(game->pos[1] + *y)] == 1 || *game->map[(int)(game->pos[1] + *y)] == 2)
		*y = 0;
	if (game->map[(int)(game->pos[1] + *y)][(int)(game->pos[0] + *x)] == 1 || \
		game->map[(int)(game->pos[1] + *y)][(int)(game->pos[0] + *x)] == 2)
		*x = 0;
}

int	move(t_cubed *master)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	if (master->game->w)
		get_direction_move(&x, &y, get_dir(master->game, 0), master->game);
	if (master->game->a)
		get_direction_move(&x, &y, get_dir(master->game, -90), master->game);
	if (master->game->s)
		get_direction_move(&x, &y, get_dir(master->game, 180), master->game);
	if (master->game->d)
		get_direction_move(&x, &y, get_dir(master->game, 90), master->game);
	printf("%f\n", master->game->pos[0]);
	printf("%f\n", master->game->pos[1]);
	return (0);
}

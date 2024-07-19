#include "cubed.h"

/*static void	direction_top(double *x, double *y, int dir)
{
	if ((dir >= 337 && dir < 360) && (dir >= 0 && dir < 23))
		*y = -1;
	else if (dir >= 23 && dir < 68)
	{
		*x = 1;
		*y = -1;
	}
	else if (dir >= 68 && dir < 113)
		*x = 1;
	else if (dir >= 113 && dir < 158)
	{
		*x = 1;
		*y = 1;
	}
}

static void	direction_bottom(double *x, double *y, int dir)
{
	if (dir >= 158 && dir < 203)
		*y = 1;
	else if (dir >= 203 && dir < 248)
	{
		*x = -1;
		*y = 1;
	}
	else if (dir >= 248 && dir < 293)
		*x = -1;
	else if (dir >= 293 && dir < 337)
	{
		*x = -1;
		*y = -1;
	}
}

static void	get_direction_move(double *x, double *y, int dir, t_game *game)
{
	int	new_x;
	int	new_y;
	int	old_x;
	int	old_y;

	if (dir >= 337 && dir < 158)
		direction_top(x, y, dir);
	else
		direction_bottom(x, y, dir);
	*x = MOVESPEED * *x;
	*y = MOVESPEED * *y;
	new_x = (game->pos[0] + *x);
	new_y = (game->pos[1] + *y);
	old_x = (game->pos[0]);
	old_y = (game->pos[1]);
	if (game->map[new_y][old_x] != '1' && game->map[new_y][old_x] != '2')
		*y = 0;
	if (game->map[old_y][new_x] != '1' && game->map[old_y][new_x] != '2')
		*x = 0;
}

static void	print_map(t_cubed *master)
{
	for (int i = 0; master->game->map[i]; i++)
	{
		for (int i2 = 0; master->game->map[i][i2]; i2++)
		{
			if (i != master->game->pos[1] && i2 != master->game->pos[0])
				printf("\033[32;1mp\033[0m");
			else
				printf("%c", master->game->map[i][i2]);
		}
		printf("\n");
	}
}*/

static void	move_w(double *x, double *y, t_cubed *master)
{
	*x = (master->game->pos[0] + master->game->dir_x * MOVESPEED);
	*y = (master->game->pos[1] + master->game->dir_y * MOVESPEED);
	if (master->game->map[(int)*y][(int)master->game->pos[0]] != '1' && \
		master->game->map[(int)*y][(int)master->game->pos[0]] != '2')
		master->game->pos[1] = *y;
	if (master->game->map[(int)master->game->pos[1]][(int)*x] != '1' && \
		master->game->map[(int)master->game->pos[1]][(int)*x] != '2')
		master->game->pos[0] = *x;
}

static void	move_a(double *x, double *y, t_cubed *master)
{
	*x = (master->game->pos[0] - -master->game->dir_y * MOVESPEED);
	*y = (master->game->pos[1] - master->game->dir_x * MOVESPEED);
	if (master->game->map[(int)*y][(int)master->game->pos[0]] != '1' && \
		master->game->map[(int)*y][(int)master->game->pos[0]] != '2')
		master->game->pos[1] = *y;
	if (master->game->map[(int)master->game->pos[1]][(int)*x] != '1' && \
		master->game->map[(int)master->game->pos[1]][(int)*x] != '2')
		master->game->pos[0] = *x;
}

static void	move_s(double *x, double *y, t_cubed *master)
{
	*x = (master->game->pos[0] - master->game->dir_x * MOVESPEED);
	*y = (master->game->pos[1] - master->game->dir_y * MOVESPEED);
	if (master->game->map[(int)*y][(int)master->game->pos[0]] != '1' && \
		master->game->map[(int)*y][(int)master->game->pos[0]] != '2')
		master->game->pos[1] = *y;
	if (master->game->map[(int)master->game->pos[1]][(int)*x] != '1' && \
		master->game->map[(int)master->game->pos[1]][(int)*x] != '2')
		master->game->pos[0] = *x;
}

static void	move_d(double *x, double *y, t_cubed *master)
{
	*x = (master->game->pos[0] + -master->game->dir_y * MOVESPEED);
	*y = (master->game->pos[1] + master->game->dir_x * MOVESPEED);
	if (master->game->map[(int)*y][(int)master->game->pos[0]] != '1' && \
		master->game->map[(int)*y][(int)master->game->pos[0]] != '2')
		master->game->pos[1] = *y;
	if (master->game->map[(int)master->game->pos[1]][(int)*x] != '1' && \
		master->game->map[(int)master->game->pos[1]][(int)*x] != '2')
		master->game->pos[0] = *x;
}

int	move(int rot, t_cubed *master)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	if (rot == 0)
		move_w(&x, &y, master);
	else if (rot == 1)
		move_a(&x, &y, master);
	else if (rot == 2)
		move_s(&x, &y, master);
	else
		move_d(&x, &y, master);
	return ((x + y));
}

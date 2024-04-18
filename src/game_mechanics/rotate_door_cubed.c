#include "cubed.h"

int	rotate(int dir, t_cubed *master)
{
	double	tmp;

	tmp = master->game->dir + (dir * ROTSPEED);
	if (tmp <= 0)
		tmp = 360;
	else if (tmp >= 360)
		tmp = 0;
	master->game->dir = tmp;
	return (1);
}

static int	infront(int dir, int *x, int *y)
{
	if ((dir >= 337 && dir <= 360) || (dir >= 0 && dir <= 23))
	{
		*y -= 1;
		return (1);
	}
	else if (dir >= 68 && dir < 158)
	{
		*x += 1;
		return (1);
	}
	else if (dir >= 158 && dir <= 203)
	{
		*y += 1;
		return (1);
	}
	else if (dir >= 248 && dir <= 293)
	{
		*x -= 1;
		return (1);
	}
	return (0);
}

static int	isdoor(int x, int y, t_game *game)
{
	if (game->map[y][x] == '2')
		return (1);
	else if (game->map[y][x] == '3')
		return (2);
	else
		return (0);
}

int	handle_door(t_cubed *master)
{
	int	x;
	int	y;
	int	door;

	x = master->game->pos[0];
	y = master->game->pos[1];
	if (infront(master->game->dir, &x, &y))
	{
		door = isdoor(x, y, master->game);
		if (!door)
			return (0);
		else if (door == 1)
			master->game->map[y][x] = '3';
		else if (door == 2)
			master->game->map[y][x] = '2';
		return (1);
	}
	return (0);
}

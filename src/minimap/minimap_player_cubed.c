#include "cubed.h"
/*
static void	calc_end(t_player *player, t_cubed *master)
{
	double	radius;
	int		standart;

	standart = (int)master->game->dir;
	if (standart >= 360)
		standart = standart - 360;
	radius = standart * M_PI / 180;
	player->ex = player->cx + (MINI_SIZE * 2 * cos(radius));
	player->ey = player->cy + (MINI_SIZE * 2 * sin(radius));
}

static void	setup_player(t_player *player)
{
	player->dx = abs(player->ex - player->cx);
	player->dy = abs(player->ey - player->cy);
	if (player->cx < player->ex)
		player->sx = 1;
	else 
		player->sx = -1;
	if (player->cy < player->ey)
		player->sy = 1;
	else
		player->sy = -1;
	player->tmp = player->dx - player->dy;
}

static void	draw(t_player *player, t_cubed *master)
{
	while (player->cx != player->ex || player->cy != player->ey)
	{
		//put_pixel_cubed(img, player->cx, player->cy, 0xFF0000FF);
		master->draw->draw_buffer[player->cx][player->cy] = 0xFF0000FF;
		player->tmp2 = 2 * player->tmp;
		if (player->tmp2 > -(player->dy))
		{
			player->tmp -= player->dy;
			player->cx += player->sx;
		}
		if (player->tmp2 < player->dx)
		{
			player->tmp += player->dx;
			player->cy += player->sy;
		}
	}
}

void	draw_player(int x, int y, t_cubed *master)
{
	t_player	player;

	player.cx = x - master->map->size / 2;
	player.cy = y - master->map->size / 2;
	calc_end(&player, master);
	setup_player(&player);
	draw(&player, master);
}*/

static void	draw_line(int x0, int y0, int x1, int y1, t_cubed *master)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	tmp;
	int	br;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	tmp = dx + dy;
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	while (x0 != x1 && y0 != y1)
	{
		master->draw->draw_buffer[x0][y0] = 0xFF0000FF;
		br = 2 * tmp;
		if (br >= dy)
		{
			tmp += dy;
			x0 += sx;
		}
		if (br <= dx)
		{
			tmp += dx;
			y0 += sy;
		}
	}
}

void	draw_player(int x, int y, t_cubed *master)
{
	t_player	player;

	player.cx = x - master->map->size / 2;
	player.cy = y - master->map->size / 2;
	player.ex = player.cx + master->map->size / 4;
	player.ey = player.cy;
	player.dx = player.cx;
	player.dy = player.cy + master->map->size / 4;
	player.sx = player.cx + master->game->dir_x;
	player.sy = player.cy + master->game->dir_y;
	draw_line(player.ex, player.ey, player.dx, player.dy, master);
	draw_line(player.ex, player.ey, player.sx, player.sy, master);
	draw_line(player.dx, player.dy, player.sx, player.sy, master);
}

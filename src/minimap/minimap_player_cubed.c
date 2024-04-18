#include "cubed.h"

static void	calc_end(t_player *player, t_cubed *master)
{
	double	radius;
	int		standart;

	standart = ((int)master->game->dir - 90);
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

static void	draw(t_player *player, mlx_image_t *img)
{
	while (player->cx != player->ex || player->cy != player->ey)
	{
		put_pixel_cubed(img, player->cx, player->cy, 0xFF0000FF);
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

void	draw_player(int x, int y, mlx_image_t *img, t_cubed *master)
{
	t_player	player;

	player.cx = x - master->map->size / 2;
	player.cy = y - master->map->size / 2;
	calc_end(&player, master);
	setup_player(&player);
	draw(&player, img);
}

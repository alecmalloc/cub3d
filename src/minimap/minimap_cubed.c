#include "cubed.h"

void	set_minimap(t_cubed *master)
{
	master->map->start_x = (int)(WIDTH * 0.05);
	master->map->start_y = (int)(WIDTH * 0.05);
	master->map->end_x = master->map->start_x * 2;
	master->map->end_y = master->map->start_y * 2;
	master->map->offset_x = master->map->start_x / 2;
	master->map->offset_y = master->map->start_y / 2;
	master->map->size = master->map->start_x / MINI_SIZE;
	master->map->cur_x = master->map->start_x;
	master->map->cur_y = master->map->start_y;
}

static uint32_t	get_color(int x, int y, t_cubed *master)
{
	if (x < 0 || y < 0)
		return (0xC0C0C0FF);
	else if (x >= master->parser->map->x_len || y >= master->parser->map->y_len)
		return (0xC0C0C0FF);
	else if ((int)master->game->map[y][x] == '1')
		return (0xf7c93fFF);
	else if ((int)master->game->map[y][x] == '2')
		return (0x333333FF);
	else if ((int)master->game->map[y][x] == '4')
		return (0x254194FF);
	return (0xdddcd7FF);
}

static void	put_minimap(int x, int y, t_cubed *master)
{
	uint32_t	color;
	int			z_x;
	int			z_y;

	color = get_color(x, y, master);
	z_y = master->map->cur_y;
	while (z_y < master->map->cur_y + master->map->size)
	{
		z_x = master->map->cur_x;
		while (z_x < master->map->cur_x + master->map->size)
		{
			//put_pixel_cubed(img, z_x, z_y, color);
			master->draw->draw_buffer[z_x][z_y] = color;
			z_x++;
		}
		z_y++;
	}
	if (x == (int)master->game->pos[0] && y == (int)master->game->pos[1])
		draw_player(z_x, z_y, master);
}

void	load_minimap(t_cubed *master)
{
	int	x;
	int	y;

	y = master->game->pos[1] - MINI_SIZE;
	while (y < master->game->pos[1] + MINI_SIZE)
	{
		x = master->game->pos[0] - MINI_SIZE;
		while (x < master->game->pos[0] + MINI_SIZE)
		{
			put_minimap(x, y, master);
			x++;
			master->map->cur_x += master->map->size;
		}
		y++;
		master->map->cur_y += master->map->size;
		master->map->cur_x = master->map->offset_x;
	}
	master->map->cur_x = master->map->offset_x;
	master->map->cur_y = master->map->offset_y;
}

#include "casting.h"
#include "cubed.h"

static void	decide_dir(t_casting *caster, t_cubed *master)
{
	if (caster->ray_dir_x < 0)
	{
		caster->step_x = -1;
		caster->dist_to_x = (master->game->pos[0] - caster->map_x) *\
				    caster->delta_dist_x;
	}
	else
	{
		caster->step_x = 1;
		caster->dist_to_x = (caster->map_x + 1.0 - master->game->pos[0]) *\
				    caster->delta_dist_x;
	}
	if (caster->ray_dir_y < 0)
	{
		caster->step_y = -1;
		caster->dist_to_y = (master->game->pos[1] - caster->map_y) *\
				    caster->delta_dist_y;
	}
	else
	{
		caster->step_y = 1;
		caster->dist_to_y = (caster->map_y + 1.0 - master->game->pos[1]) *\
				    caster->delta_dist_y;
	}
}

static void	set_up_caster(t_casting *caster, t_cubed *master, int x)
{
	caster->camera_x = 2 * x / (double)WIDTH - 1;
	caster->ray_dir_x = master->game->dir_x + master->game->plane_x * \
			    caster->camera_x;
	caster->ray_dir_y = master->game->dir_y + master->game->plane_y * \
			    caster->camera_x;
	caster->map_x = (int)master->game->pos[0];
	caster->map_y = (int)master->game->pos[1];
	caster->delta_dist_x = fabs(1 / caster->ray_dir_x);
	if (caster->delta_dist_x == 0)
		caster->delta_dist_x = 1e30;
	caster->delta_dist_y = fabs(1 / caster->ray_dir_y);
	if (caster->delta_dist_y == 0)
		caster->delta_dist_y = 1e30;
	caster->hit = '0';
	caster->side = 0;
	decide_dir(caster, master);
}

static void	check_hit(t_casting *caster, t_cubed *master)
{
	while (caster->hit == '0')
	{
		if (caster->dist_to_x < caster->dist_to_y)
		{
			caster->dist_to_x += caster->delta_dist_x;
			caster->map_x += caster->step_x;
			caster->side = 0;
		}
		else
		{
			caster->dist_to_y += caster->delta_dist_y;
			caster->map_y += caster->step_y;
			caster->side = 1;
		}
		if (master->game->map[caster->map_y][caster->map_x] != 0)
			caster->hit = master->game->map[caster->map_y][caster->map_x];
	}
}

void	caster(t_cubed *master)
{
	t_casting	caster;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		set_up_caster(&caster, master, x);
		check_hit(&caster, master);
		put_rays(x, &caster, master);
		x++;
	}

}

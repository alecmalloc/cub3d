#include "cubed.h"

// load up main struct and initalize the mlx window
int	main(int argc, char **argv)
{
	t_cubed	*cubed;
	int		ret;

	cubed = NULL;
	init_all(&cubed);
	if (argc != 2 && argv)
		return (print_error(WRA_ERR, &cubed));
	ret = parser(argv[1], cubed);
	if (ret)
		return (print_error(ret, &cubed));
	cubed->game->dir = (double)cubed->parser->map->player_dir;
	cubed->game->pos[0] = cubed->parser->map->player_pos[0];
	cubed->game->pos[1] = cubed->parser->map->player_pos[1];
	start_game(cubed);
	free_all(&cubed);
	return (EXIT_SUCCESS);
}

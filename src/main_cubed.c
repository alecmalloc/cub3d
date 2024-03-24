#include "cubed.h"

// load up main struct and initalize the mlx window
int	main(int argc, char *argv[])
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
	ret = window_init(cubed);
	if (ret)
		return (print_error(ret, &cubed));
	start_game(cubed);
	free_all(&cubed);

	return (EXIT_SUCCESS);
}

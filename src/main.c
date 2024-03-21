#include "cubed.h"

// load up main struct and initalize the mlx window
int	main(int argc, char *argv[])
{
/*
	t_cubed	cubed;

	if (init_structs(&cubed) == NULL)
		return (EXIT_FAILURE);
	if (window_init(&cubed) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	destroy_structs(&cubed);
*/

	t_cubed	*cubed;
	int		ret;

	cubed = NULL;
	init_all(&cubed);
	if (argc != 2 && argv)
		return (print_error(WRA_ERR, &cubed));
	ret = parser(argv[1], cubed);
	if (ret)
		return (print_error(ret, &cubed));
	free_all(&cubed);

	return (EXIT_SUCCESS);
}

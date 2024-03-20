/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:48:55 by aeastman          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/16 17:29:01 by aeastman         ###   ########.fr       */
=======
/*   Updated: 2024/03/16 12:44:25 by mbartsch         ###   ########.fr       */
>>>>>>> parser
/*                                                                            */
/* ************************************************************************** */

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
=======
	t_cubed	*cubed;
	int		ret;

	cubed = NULL;
	init_all(&cubed);
	if (argc != 2 && argv)
		return (print_error(WRA_ERR, &cubed));
	ret = parser(argv[1], cubed);
	if (ret)
		return (print_error(ret, &cubed));
	//if (mlx_handler(&cubed) == EXIT_FAILURE)
	//	return (EXIT_FAILURE);
	free_all(&cubed);
*/
	return (EXIT_SUCCESS);
}

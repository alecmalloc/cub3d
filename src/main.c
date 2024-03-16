/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:48:55 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/16 12:44:25 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

// load up main struct and initalize the mlx window
int	main(int argc, char *argv[])
{
	t_cubed	*cubed;

	cubed = NULL;
	init_all(cubed);
	if (argc != 2 && argv)
		;
	parser(argv[1], cubed);
	//if (mlx_handler(&cubed) == EXIT_FAILURE)
	//	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

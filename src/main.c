/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:48:55 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/16 17:29:01 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

// load up main struct and initalize the mlx window
int	main(void)
{
	t_cubed	cubed;

	if (init_structs(&cubed) == NULL)
		return (EXIT_FAILURE);
	if (window_init(&cubed) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	destroy_structs(&cubed);
	return (EXIT_SUCCESS);
}

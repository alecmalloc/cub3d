/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:48:55 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/14 11:01:53 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	main(void)
{
	t_cubed	cubed;

	cubed.ptr_mlx = mlx_init(500, 500, "cub3d", false);
	if (!(cubed.ptr_mlx))
		return (EXIT_FAILURE);
	mlx_set_window_pos(cubed.ptr_mlx, 20, 30);
	mlx_loop(cubed.ptr_mlx);
	mlx_terminate(cubed.ptr_mlx);

	return (EXIT_SUCCESS);
}

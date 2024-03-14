/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:48:29 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/14 13:53:22 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cubed.h"

int	mlx_handler(t_cubed	*cubed)
{
	cubed->ptr_mlx = mlx_init(1000, 500, "cub3d", false);
	if (!(cubed->ptr_mlx))
		return (EXIT_FAILURE);
	mlx_set_window_pos(cubed->ptr_mlx, 20, 30);
	mlx_loop(cubed->ptr_mlx);
	mlx_terminate(cubed->ptr_mlx);
	return (EXIT_SUCCESS);
}

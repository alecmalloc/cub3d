/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_cubed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:03:45 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:03:46 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	init_window(t_cubed **cubed)
{
	(*cubed)->mlx_inst = mlx_init(WIDTH, HIGHT, "cub3d", false);
	if (!((*cubed)->mlx_inst))
		return (MLX_INIT_ERR);
	return (0);
}

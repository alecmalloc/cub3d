/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:23:21 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/14 13:51:25 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

// c lib includes
# include <stdlib.h>

// include MLX42
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct Cubed {
	mlx_t	*ptr_mlx;
}	t_cubed;



// /mlx
int	mlx_handler(t_cubed	*cubed);


#endif
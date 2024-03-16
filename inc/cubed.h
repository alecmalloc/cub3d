/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:23:21 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/16 13:54:46 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

// c lib includes
# include <stdlib.h>
# include <string.h>

// include MLX42
# include "MLX42.h"

typedef struct Images{
	mlx_image_t	*ceiling;
	mlx_image_t *floor;

}	t_images;

// cubed main struct to store most everything
typedef struct Cubed {
	mlx_t		*mlx_inst;
	t_images	*images;
}	t_cubed;

// /mlx
int		window_init(t_cubed	*cubed);

// /graphics
void	put_backdrop(t_cubed *cubed);

#endif
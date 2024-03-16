/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:23:21 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/16 17:21:28 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

// c lib includes
# include <stdlib.h>
# include <string.h>

// include MLX42
# include "MLX42.h"

// strucure for custom RBG filled images
typedef struct Fill_img{
	mlx_image_t	*image;
	int			r;
	int			g;
	int			b;
} t_f_img;

// cubed main struct to store most everything
typedef struct Cubed {
	mlx_t		*mlx_inst;
	t_f_img		*ceiling;
	t_f_img		*floor;
}	t_cubed;

// /mlx
int		window_init(t_cubed	*cubed);

// /graphics
void	put_backdrop(t_cubed *cubed);

// /structs
void	*init_structs(t_cubed *cubed);
void	destroy_structs(t_cubed *cubed);

#endif
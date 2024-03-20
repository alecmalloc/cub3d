/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:23:21 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/16 12:38:01 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

// c lib includes
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>

// include MLX42
# include "../MLX42/include/MLX42/MLX42.h"
# include "parser_cub.h"
# include "error_cub.h"
# include "../libft/includes/libft.h"

typedef struct Cubed
{
	mlx_t		*ptr_mlx;
	t_parser	*parser;
}	t_cubed;

// /mlx
int		mlx_handler(t_cubed	*cubed);
//init
int		init_all(t_cubed **cubed);
//free
void	free_all(t_cubed **cubed);
//error
int		print_error(int err_code, t_cubed **cubed);
//parser
int		parser(char *pathname, t_cubed *master);

#endif

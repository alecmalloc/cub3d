/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mimimap_cub.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:05:49 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:05:50 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIMIMAP_CUB_H
# define MIMIMAP_CUB_H

# define MINI_SIZE 8

struct	s_cubed;

typedef struct s_minimap{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	offset_x;
	int	offset_y;
	int	size;
	int	cur_x;
	int	cur_y;
}	t_minimap;

int		init_minimap(struct s_cubed **master);
void	free_minimap(t_minimap **map);
void	load_minimap(struct s_cubed *cubed);
void	set_minimap(struct s_cubed *cuebd);

#endif

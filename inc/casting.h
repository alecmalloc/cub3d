/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:05:27 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:06:40 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H

struct	s_cubed;

typedef struct casting {
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	dist_to_x;
	double	dist_to_y;
	double	delta_dist_x;
	double	delta_dist_y;

	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		side;

	char	hit;
}	t_casting;

void	caster(struct s_cubed *master);

#endif

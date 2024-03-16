/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:20:04 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/16 17:28:53 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	destroy_f_imgs(t_cubed *cubed)
{
	free(cubed->ceiling);
	free(cubed->floor);
}

void	destroy_structs(t_cubed *cubed)
{
	destroy_f_imgs(cubed);
}
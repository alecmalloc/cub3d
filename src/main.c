/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:48:55 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/14 16:15:50 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	*init_structs(t_cubed *cubed)
{
	t_images	*images;

	images = malloc(sizeof(t_images));
	if (!images)
		return (NULL);
	cubed->images = images;
	return ((void *)1);
}

void	destroy_structs(t_cubed *cubed)
{
	free(cubed->images);
}

// load up main struct and initalize the mlx window
int	main(void)
{
	t_cubed	cubed;

	if (init_structs(&cubed) == NULL)
		return (EXIT_FAILURE);
	if (window_init(&cubed) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	destroy_structs(&cubed);
	return (EXIT_SUCCESS);
}

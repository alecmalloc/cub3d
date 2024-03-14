/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:48:55 by aeastman          #+#    #+#             */
/*   Updated: 2024/03/14 13:48:56 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	main(void)
{
	t_cubed	cubed;

	if (mlx_handler(&cubed) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

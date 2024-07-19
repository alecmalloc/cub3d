/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_func_3_cubed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:02:05 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:02:06 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char	*print_direction(int err)
{
	if (err == 0)
		return ("North");
	else if (err == 1)
		return ("East");
	else if (err == 2)
		return ("South");
	else
		return ("West");
}

char	*print_boto(int err)
{
	if (err == 0)
		return ("Floor");
	else
		return ("Ceiling");
}

void	print_loadtex(int err)
{
	if (err == 194)
		printf("Error\nLoading Door Texture failed\n");
	else if (err == 195)
		printf("Error\nLoading Sprite Texturei failed\n");
	else
		printf("Error\nLoading %s Texture failed\n", print_direction(err % 190));
}

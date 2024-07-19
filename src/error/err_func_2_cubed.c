/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_func_2_cubed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:02:00 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:02:03 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	print_missingn(int err)
{
	printf("Error\n%s RGB number missing\n", print_boto(err % 140));
}

void	print_doublen(int err)
{
	printf("Error\n%s double assingment\n", print_boto(err % 150));
}

void	print_wrongn(int err)
{
	printf("Error\n%s RGB Number wrong\n", print_boto(err % 160));
}

void	print_wrongfn(int err)
{
	printf("Error\n%s RGB Number wrong format\n", print_boto(err % 170));
}

void	print_wrongsf(int err)
{
	printf("Error\n%s Path Wrong Suffix\n", print_direction(err % 180));
}

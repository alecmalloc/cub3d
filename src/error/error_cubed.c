/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cubed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:02:10 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:02:11 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	print_error_map(int err)
{
	if (err < 190)
		print_wrongsf(err);
	else if (err < 200)
		print_loadtex(err);
	else if (err == 200)
		printf("Erorr\nMap not found\n");
	else if (err == 201)
		printf("Error\nWrong Character in Map\n");
	else if (err == 202)
		printf("Error\nDouble Player in Map\n");
	else if (err == 203)
		printf("Error\nOpen Wall in Map\n");
}

int	print_error(int err_code, t_cubed **cubed)
{
	if (err_code < 100)
		print_single(err_code);
	else if (err_code < 110)
		print_doublep(err_code);
	else if (err_code < 120)
		print_unaccesp(err_code);
	else if (err_code < 130)
		print_missingp(err_code);
	else if (err_code < 140)
		print_wrongp(err_code);
	else if (err_code < 150)
		print_missingn(err_code);
	else if (err_code < 160)
		print_doublen(err_code);
	else if (err_code < 170)
		print_wrongn(err_code);
	else if (err_code < 180)
		print_wrongfn(err_code);
	else
		print_error_map(err_code);
	free_all(cubed);
	return (EXIT_FAILURE);
}

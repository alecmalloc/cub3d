/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:28:10 by mbartsch          #+#    #+#             */
/*   Updated: 2023/07/03 16:28:12 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	uint_parse(unsigned int nbr, char *buffer)
{
	int	z;
	int	sp;

	z = 0;
	if (nbr == 0)
		buffer[z++] = '0';
	while (nbr != 0)
	{
		sp = nbr % 10;
		if (sp < 10)
			sp += '0';
		else
			sp = (sp -10) + '0';
		buffer[z] = sp;
		nbr /= 10;
		z++;
	}
	buffer[z] = '\0';
	swap_buff(buffer, z);
}

static void	uint_before(t_prints *printer)
{
	if (!printer->minus && printer->dot && !printer->dot)
		print_width(printer);
	if (!printer->minus)
		print_width(printer);
}

static void	uint_print(char *buffer, t_prints *printer)
{
	uint_before(printer);
	print_precision(buffer, printer);
	ft_put_str(buffer, printer);
	if (printer->minus)
		print_width(printer);
}

void	ft_printf_uint(t_prints *printer)
{
	unsigned int	nbr;
	char			*buffer;

	nbr = (unsigned int) va_arg(printer->args, unsigned int);
	buffer = (char *)malloc(sizeof(char) * 17);
	if (!buffer)
		exit(1);
	uint_parse(nbr, buffer);
	check_len(buffer, printer);
	uint_print(buffer, printer);
	free(buffer);
}

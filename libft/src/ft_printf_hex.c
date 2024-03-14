/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:27:42 by mbartsch          #+#    #+#             */
/*   Updated: 2023/07/03 16:27:46 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	hex_parse(long nbr, char *buffer, t_prints *printer)
{
	int	z;
	int	sp;

	z = 0;
	if (nbr == 0)
	{
		buffer[z++] = '0';
		printer->pos = 1;
	}
	while (nbr != 0)
	{
		sp = nbr % 16;
		if (sp < 10)
			sp += '0';
		else
			sp = (sp - 10) + (printer->conv - 23);
		buffer[z++] = sp;
		nbr /= 16;
	}
	buffer[z] = '\0';
	swap_buff(buffer, z);
}

static void	hex_before(t_prints *printer)
{
	if (!printer->minus && printer->dot && !printer->zero)
		print_width(printer);
	if (printer->hash && !printer->pos)
	{
		printer->ret_value += write(1, "0", 1);
		printer->ret_value += write(1, &printer->conv, 1);
	}
	if (!printer->minus)
		print_width(printer);
}

static void	hex_print(char *buffer, t_prints *printer)
{
	if (printer->hash && !printer->pos)
		printer->width -= 2;
	hex_before(printer);
	print_precision(buffer, printer);
	ft_put_str(buffer, printer);
	if (printer->minus)
		print_width(printer);
}

void	ft_printf_hex(t_prints *printer)
{
	long	nbr;
	char	*buffer;

	nbr = (long) va_arg(printer->args, unsigned int);
	buffer = (char *)malloc(sizeof(char) * 20);
	if (!buffer)
		exit(1);
	hex_parse(nbr, buffer, printer);
	check_len(buffer, printer);
	hex_print(buffer, printer);
	free(buffer);
}

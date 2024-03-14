/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:27:22 by mbartsch          #+#    #+#             */
/*   Updated: 2023/07/03 16:27:24 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	nbr_parse(long nbr, char *buffer, t_prints *printer)
{
	int	z;
	int	sp;

	z = 0;
	if (nbr < 0)
	{
		printer->pos = 1;
		nbr *= -1;
	}
	else if (nbr == 0)
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

static void	nbr_before(t_prints *printer)
{
	if (!printer->minus && (printer->dot || !printer->zero))
		print_width(printer);
	if (printer->pos)
		printer->ret_value += write(1, "-", 1);
	else if (printer->plus)
		printer->ret_value += write(1, "+", 1);
	else if (printer->space)
		printer->ret_value += write(1, " ", 1);
	if (!printer->minus)
		print_width(printer);
}

void	nbr_print(char *buffer, t_prints *printer)
{
	if (printer->space || printer->plus || printer->pos)
		printer->width--;
	nbr_before(printer);
	print_precision(buffer, printer);
	ft_put_str(buffer, printer);
	if (printer->minus)
		print_width(printer);
}

void	ft_printf_dec(t_prints *printer)
{
	long	nbr;
	char	*buffer;

	nbr = (long) va_arg(printer->args, int);
	buffer = (char *)malloc(sizeof(char) * 20);
	if (!buffer)
		exit(1);
	nbr_parse(nbr, buffer, printer);
	check_len(buffer, printer);
	nbr_print(buffer, printer);
	free(buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:27:05 by mbartsch          #+#    #+#             */
/*   Updated: 2023/07/03 16:27:08 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	char_width(t_prints *printer)
{
	while (--printer->width > 0)
		printer->ret_value += write(1, " ", 1);
}

static void	char_print(char c, t_prints *printer)
{
	if (printer->minus)
	{
		printer->ret_value += write(1, &c, 1);
		char_width(printer);
	}
	else
	{
		char_width(printer);
		printer->ret_value += write(1, &c, 1);
	}
}

void	ft_printf_char(t_prints *printer)
{
	char	c;

	c = (char) va_arg(printer->args, int);
	char_print(c, printer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:28:07 by mbartsch          #+#    #+#             */
/*   Updated: 2023/07/03 16:28:08 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	str_before(t_prints *printer)
{
	if (!printer->minus && !printer->zero)
		print_width(printer);
	if (!printer->minus)
		print_width(printer);
}

static void	str_print_str(char *str, t_prints *printer)
{
	int	len;

	len = ft_strlen(str);
	if (len < printer->precision)
		ft_put_str(str, printer);
	else if (printer->precision || printer->zero)
	{
		len = 0;
		while (len < printer->precision && str[len])
		{
			printer->ret_value += write(1, &str[len], 1);
			len++;
		}
	}
	else
		ft_put_str(str, printer);
}

static void	str_print(char *str, t_prints *printer)
{
	str_before(printer);
	if (!(printer->dot && printer->precision == 0) && (!(printer->null && \
					printer->dot && printer->precision < (int) ft_strlen(str))))
		str_print_str(str, printer);
	if (printer->minus)
		print_width(printer);
}

static void	str_check_len(int len, t_prints *printer)
{
	if (printer->precision <= len && printer->precision > 0 && !printer->null)
		printer->width -= printer->precision;
	else if (printer->dot && printer->precision == 0)
		;
	else if (!(printer->precision < len && printer->dot && printer->null))
		printer->width -= len;
}

void	ft_printf_str(t_prints *printer)
{
	char	*str;

	str = (char *) va_arg(printer->args, char *);
	if (!str)
	{
		printer->null = 1;
		str = "(null)\0";
	}
	str_check_len(ft_strlen(str), printer);
	str_print(str, printer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:27:48 by mbartsch          #+#    #+#             */
/*   Updated: 2023/07/03 16:27:53 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

const char	*printf_atoi(const char *str, t_prints *printer, int mode)
{
	int	zahl;

	zahl = 0;
	while (*str >= '0' && *str <= '9')
	{
		zahl = zahl * 10 + (*str - '0');
		str++;
	}
	if (mode == 1)
		printer->width = zahl;
	else
		printer->precision = zahl;
	str--;
	return (str);
}

const char	*parse_arg(const char *str, t_prints *printer)
{
	while (str++)
	{
		if (*str == '#')
			printer->hash = 1;
		else if (*str == ' ')
			printer->space = 1;
		else if (*str == '+')
			printer->plus = 1;
		else if (*str == '-')
			printer->minus = 1;
		else if (*str == '0')
			printer->zero = 1;
		else if (*str == '.')
			printer->dot = 1;
		else if (*str > '0' && *str <= '9' && printer->dot == 0)
			str = printf_atoi(str, printer, 1);
		else if (*str > '0' && *str <= '9' && printer->dot == 1)
			str = printf_atoi(str, printer, 2);
		else
		{
			printer->conv = *str;
			break ;
		}
	}
	return (str);
}

void	print_arg(t_prints *printer)
{
	if (printer->conv == 'c')
		ft_printf_char(printer);
	else if (printer->conv == 's')
		ft_printf_str(printer);
	else if (printer->conv == 'p')
		ft_printf_ptr(printer);
	else if (printer->conv == 'd' || printer->conv == 'i')
		ft_printf_dec(printer);
	else if (printer->conv == 'u')
		ft_printf_uint(printer);
	else if (printer->conv == 'x' || printer->conv == 'X')
		ft_printf_hex(printer);
	else if (printer->conv == '%')
		ft_printf_prct(printer);
}

void	parse_str(const char *str, t_prints *printer)
{
	while (*str)
	{
		if (*str == '%')
		{
			str = parse_arg(str, printer);
			print_arg(printer);
			init_printer(printer);
		}
		else if (*str)
			printer->ret_value += write(1, &*str, 1);
		str++;
	}
}

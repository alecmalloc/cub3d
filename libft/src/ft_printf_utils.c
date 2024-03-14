/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:28:18 by mbartsch          #+#    #+#             */
/*   Updated: 2023/07/03 16:28:20 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	print_precision(char *str, t_prints *printer)
{
	int	len;

	len = ft_strlen(str);
	while (printer->precision > 0 && printer->precision > len)
	{
		printer->ret_value += write(1, "0", 1);
		printer->precision--;
	}
}

void	print_width(t_prints *printer)
{
	char	c;

	if (printer->zero && !printer->minus && !printer->dot)
		c = '0';
	else
		c = ' ';
	while (printer->width > 0)
	{
		printer->ret_value += write(1, &c, 1);
		printer->width--;
	}
}

void	print_before(t_prints *printer)
{
	if (printer->plus)
		printer->ret_value += write(1, "+", 1);
	else if (printer->space)
		printer->ret_value += write(1, " ", 1);
}

void	ft_put_str(char *buffer, t_prints *printer)
{
	char	*p;

	p = buffer;
	if (!(printer->dot && ft_strlen(p) == 1 && p[0] == '0'\
			&& printer->precision <= 0))
	{
		while (*p)
		{
			printer->ret_value += write(1, p, 1);
			p++;
		}
	}
}

void	check_len(char *str, t_prints *printer)
{
	int	buff_len;

	buff_len = ft_strlen(str);
	if (printer->precision > buff_len && printer->precision != 0)
		printer->width -= printer->precision;
	else if (buff_len == 1 && str[0] == '0' && printer->dot)
		;
	else
		printer->width -= buff_len;
}

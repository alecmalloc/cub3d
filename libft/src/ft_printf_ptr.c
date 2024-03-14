/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:28:00 by mbartsch          #+#    #+#             */
/*   Updated: 2023/07/03 16:28:02 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ptr_print_null(char *buffer, t_prints *printer)
{
	buffer = "(nil)\0";
	printer->width -= 5;
	printer->zero = 0;
	if (!printer->minus)
		print_width(printer);
	ft_put_str(buffer, printer);
	if (printer->minus)
		print_width(printer);
}

static void	ptr_before(t_prints *printer)
{
	if (!printer->minus && !printer->zero)
		print_width(printer);
	if (printer->plus)
		printer->ret_value += write(1, "+", 1);
	else if (printer->space)
		printer->ret_value += write(1, " ", 1);
	printer->ret_value += write(1, "0x", 2);
	if (!printer->minus)
		print_width(printer);
}

static void	ptr_parse(unsigned long long ptr, char *buffer)
{
	int	z;
	int	sp;

	z = 0;
	while (ptr != 0)
	{
		sp = ptr % 16;
		if (sp < 10)
			sp += '0';
		else
			sp += ('a' - 10);
		buffer[z] = sp;
		ptr /= 16;
		z++;
	}
	buffer[z] = '\0';
	swap_buff(buffer, z);
}

static void	ptr_print(char *buffer, t_prints *printer)
{
	if (printer->space || printer->plus)
		printer->width--;
	printer->width -= 2;
	ptr_before(printer);
	print_precision(buffer, printer);
	ft_put_str(buffer, printer);
	if (printer->minus)
		print_width(printer);
}

void	ft_printf_ptr(t_prints *printer)
{
	unsigned long long	ptr;
	char				*buffer;

	buffer = NULL;
	ptr = (unsigned long long) va_arg(printer->args, void *);
	if (ptr <= 0)
		ptr_print_null(buffer, printer);
	else
	{
		buffer = (char *)malloc(sizeof(char) * 17);
		if (!buffer)
			exit(1);
		ptr_parse(ptr, buffer);
		check_len(buffer, printer);
		ptr_print(buffer, printer);
		free(buffer);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:55:21 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/14 11:19:18 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	zahl;
	int			z;
	char		buffer[11];

	zahl = n;
	z = 0;
	if (zahl < 0)
	{
		ft_putchar_fd('-', fd);
		zahl = zahl * -1;
	}
	if (zahl > 9)
	{
		while (zahl > 0)
		{
			buffer[z++] = zahl % 10 + 48;
			zahl = zahl / 10;
		}
		z--;
		while (z >= 0)
			ft_putchar_fd(buffer[z--], fd);
	}
	else
		ft_putchar_fd((zahl + 48), fd);
}

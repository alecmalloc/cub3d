/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:46:12 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/13 14:45:55 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	zahl;
	int	minus;

	zahl = 0;
	minus = 0;
	if (*nptr == '\010')
		return (zahl);
	while (((*nptr > 7 && *nptr < 14) || *nptr == 32 || *nptr
			== '-' || *nptr == '+') && minus == 0)
	{
		if (*nptr == '-')
			minus = 1;
		else if (*nptr == '+')
			minus = 2;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
	{
		zahl = zahl * 10 + (*nptr - 48);
		nptr++;
	}
	if (minus == 1)
		zahl *= -1;
	return (zahl);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:19:02 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/19 11:40:35 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	arr_len(long int nb)
{
	size_t	len;

	if (nb == 0)
		return (1);
	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static void	prtzahl(char *zahl, long nb, int len)
{
	if (nb < 0)
	{
		zahl[0] = '-';
		nb = nb * -1;
	}
	zahl[len] = '\0';
	len--;
	zahl[len] = nb % 10 + 48;
	nb = nb / 10;
	while (nb > 0)
	{
		len--;
		zahl[len] = nb % 10 + 48;
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	long int	nbr;
	int			len;
	char		*zahl;

	nbr = n;
	len = arr_len(nbr);
	zahl = (char *)malloc((len + 1) * sizeof(char));
	if (!(zahl))
		return (NULL);
	prtzahl(zahl, nbr, len);
	return (zahl);
}

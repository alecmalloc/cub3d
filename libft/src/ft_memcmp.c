/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:03:18 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/06 14:00:15 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1d;
	unsigned char	*s2d;
	size_t			z;

	if (n == 0)
		return (0);
	s1d = (unsigned char *)s1;
	s2d = (unsigned char *)s2;
	z = -1;
	while ((z + 1) < n)
	{
		z++;
		if (!(s1d[z] == s2d[z]))
			return (s1d[z] - s2d[z]);
	}
	return (s1d[z] - s2d[z]);
}

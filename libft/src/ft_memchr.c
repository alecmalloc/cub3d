/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:30:05 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/08 13:02:08 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sd;
	unsigned char		c1;
	size_t				z;

	c1 = (unsigned char) c;
	sd = (const char unsigned *) s;
	z = 0;
	while (z < n)
	{
		if (*sd++ == c1)
			return ((void *)(sd - 1));
		z++;
	}
	return (NULL);
}

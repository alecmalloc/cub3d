/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:55:59 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/09 17:33:17 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	len_of_str(const char *str)
{
	char	*s;
	size_t	z;

	s = (char *) str;
	z = 0;
	while (*s++)
		z++;
	return (z);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*dstd;
	const char	*srcd;
	size_t		z;
	size_t		dst_len;

	dstd = (char *) dst;
	srcd = (char *) src;
	z = size;
	while (z-- != 0 && *dst != '\0')
		dst++;
	dst_len = dst - dstd;
	z = size - dst_len;
	if (z-- == 0)
		return (dst_len + len_of_str(src));
	while (*src != '\0')
	{
		if (z != 0)
		{
			*dst++ = *src;
			z--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_len + (src - srcd));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:00:46 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/06 16:00:28 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	len_of_str(char *str)
{
	size_t	z;

	z = 0;
	while (*str++)
		z++;
	return (z);
}

size_t	ft_strlcpy(char	*dst, const char *src, size_t size)
{
	size_t	z;
	size_t	i;

	i = 0;
	z = 0;
	if (size == 0)
		return (len_of_str((char *)src));
	while (src[i])
	{
		if (size && z < (size - 1))
		{
			dst[i] = src[i];
			z++;
		}
		i++;
	}
	dst[z] = '\0';
	return (i);
}

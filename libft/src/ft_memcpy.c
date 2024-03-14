/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:34:46 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/12 17:19:38 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*src1;
	char	*dest1;
	size_t	z;

	z = 0;
	if (!src && !dest)
		return (0);
	dest1 = (char *)dest;
	src1 = (char *)src;
	while (z < n)
	{
		dest1[z] = src1[z];
		z++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:27:08 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/08 18:40:03 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	checkforlittle(char *bigp, char *little, size_t len, size_t z)
{
	while (*bigp == *little && z < len)
	{
		if (*(little + 1) == '\0')
			return (1);
		bigp++;
		little++;
		z++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	z;
	char	*bigptr;
	char	*littleptr;

	bigptr = (char *)big;
	littleptr = (char *)little;
	z = 0;
	if (*littleptr == '\0' || littleptr == NULL)
		return ((char *)big);
	while (z < len && bigptr[z])
	{
		if (checkforlittle(&bigptr[z], littleptr, len, z))
			return (&bigptr[z]);
		z++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:39:52 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/13 14:59:59 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	z;
	size_t	z2;
	char	*sub;
	size_t	alloclen;

	alloclen = ft_strlen(s);
	if (alloclen < len)
		len = alloclen;
	sub = (char *)malloc((len + 1) * sizeof(*s));
	if (!sub)
		return (NULL);
	z = 0;
	z2 = 0;
	while (s[z])
	{
		if (z >= start && z2 < len)
		{
			sub[z2] = s[z];
			z2++;
		}
		z++;
	}
	sub[z2] = 0;
	return (sub);
}

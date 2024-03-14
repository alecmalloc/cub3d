/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:21:30 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/08 13:04:53 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cd;

	cd = (unsigned char) c;
	while (*s != '\0')
	{
		if (*s == cd)
			return ((char *)s);
		s++;
	}
	if (cd == '\0')
		return ((char *)s);
	return (NULL);
}

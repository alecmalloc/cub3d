/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:45:21 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/08 14:45:23 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	cd;
	char			*found;

	cd = (unsigned char) c;
	found = NULL;
	while (*s)
	{
		if (*s == cd)
			found = (char *)s;
		s++;
	}
	if (cd == '\0')
		return ((char *) s);
	return (found);
}

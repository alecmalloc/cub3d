/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:59:34 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/12 12:41:09 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	len_of_str(char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	len;
	size_t	z;

	z = 0;
	len = 0;
	len = len + len_of_str((char *)s1);
	len = len + len_of_str((char *)s2);
	concat = (char *)malloc((len + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);
	while (*s1)
	{
		concat[z] = *s1;
		s1++;
		z++;
	}
	while (*s2)
	{
		concat[z] = *s2;
		s2++;
		z++;
	}
	concat[z] = '\0';
	return (concat);
}

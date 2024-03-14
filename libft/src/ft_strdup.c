/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:21:22 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/14 11:10:11 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		z;
	size_t		len;
	char		*strret;

	len = 0;
	while (s[len])
		len++;
	strret = (char *)malloc((len + 1) * sizeof(char));
	if (!(strret))
		return (NULL);
	z = 0;
	while (s[z])
	{
		strret[z] = s[z];
		z++;
	}
	strret[z] = '\0';
	return (strret);
}

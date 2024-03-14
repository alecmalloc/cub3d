/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:10:28 by mbartsch          #+#    #+#             */
/*   Updated: 2023/05/09 18:37:43 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_nl(char *str)
{
	size_t	z;

	z = 0;
	if (!str)
		return (0);
	while (str[z] != '\0')
	{
		if (str[z] == '\n')
			return (0);
		z++;
	}
	return (1);
}

char	*join_str(char *str1, char *str2)
{
	char	*new;
	size_t	z;
	size_t	z2;

	if (!str2)
	{
		str2 = (char *)malloc(sizeof(char) * 1);
		str2[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	new = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	z = -1;
	z2 = 0;
	while (str2[++z] != '\0')
		new[z] = str2[z];
	while (str1[z2])
		new[z++] = str1[z2++];
	new[z] = '\0';
	free(str2);
	return (new);
}
/*
char	*ft_strdup(char *s)
{
	size_t		z;
	size_t		len;
	char		*strret;

	if (!s)
		return (NULL);
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

size_t	ft_strlcpy(char	*dst, char *src, size_t size)
{
	size_t	z;
	size_t	i;

	i = 0;
	z = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
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

size_t	ft_strlen(const char *str)
{
	size_t	z;

	if (!str)
		return (0);
	z = 0;
	while (str [z])
		z++;
	return (z);
}*/

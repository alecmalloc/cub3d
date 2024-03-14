/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:12:34 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/12 13:21:04 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	freeall(char **split, size_t len)
{
	while (len--)
		free(split[len]);
	return (-1);
}

static size_t	words(const char *s, char delimiter)
{
	size_t	z;
	size_t	words;

	words = 0;
	z = 0;
	while (s[z] != '\0')
	{
		if ((s[z + 1] == delimiter || s[z + 1] == '\0')
			&& !(s[z] == delimiter || s[z] == '\0'))
			words++;
		z++;
	}
	return (words);
}

static void	fillvalue(char *dst, char const *src, char delimiter)
{
	size_t	z;

	z = 0;
	while (src[z] != delimiter && src[z])
	{
		dst[z] = src[z];
		z++;
	}
	dst[z] = '\0';
}

static int	fill_split(char **split, char const *s, char delimiter)
{
	size_t	z;
	size_t	words;
	size_t	wordlen;

	z = 0;
	words = 0;
	while (s[z])
	{
		if (s[z] == delimiter && s[z])
			z++;
		else
		{
			wordlen = 0;
			while (s[z + wordlen] != delimiter && s[z + wordlen] != '\0')
				wordlen++;
			split[words] = (char *)malloc((wordlen + 1) * sizeof(char));
			if (!(split[words]))
				return (freeall(split, words - 1));
			fillvalue(split[words], &s[z], delimiter);
			words++;
			z = z + wordlen;
		}
	}
	split[words] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = (char **)malloc((words(s, c) + 1) * sizeof(char *));
	if (!(split))
		return (NULL);
	if (fill_split(split, s, c) == -1)
	{
		free(split);
		return (NULL);
	}
	return (split);
}

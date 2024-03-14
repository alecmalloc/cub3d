/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:20:18 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/09 18:52:40 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	get_beginn(char const *s1, char const *set)
{
	size_t	z;
	size_t	len;

	len = ft_strlen(s1);
	z = 0;
	while (z < len)
	{
		if (ft_strchr(set, s1[z]) == 0)
			return (z);
		z++;
	}
	return (z);
}

static size_t	get_end(char const *s1, char const *set)
{
	size_t	z;
	size_t	len;

	z = 0;
	len = ft_strlen(s1);
	while (z < len)
	{
		if (ft_strchr(set, s1[len - z - 1]) == 0)
			return (len - z);
		z++;
	}
	return (len - z);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beginn;
	size_t	end;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	beginn = get_beginn(s1, set);
	end = get_end(s1, set);
	if (beginn >= end)
		return (ft_strdup(""));
	str = (char *)ft_calloc((end - beginn + 1), sizeof(char));
	if (!(str))
		return (NULL);
	ft_strlcpy(str, s1 + beginn, end - beginn + 1);
	return (str);
}

/*int	main()
{
	char*	str = " \n \t lorem ipsum dolor sit ameti\n";
	char*	set = "\n \t";

	printf("%s", ft_strtrim(str, set));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:54:39 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/12 13:31:07 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sd;
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	sd = (char *)malloc((index + 1) * sizeof(char));
	if (!(sd))
		return (NULL);
	index = 0;
	while (s[index])
	{
		sd[index] = (f)(index, (char)s[index]);
		index++;
	}
	sd[index] = '\0';
	return (sd);
}

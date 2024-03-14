/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:04:21 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/06 16:35:50 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	z;

	z = 0;
	if (n == 0)
		return (0);
	while (s1[z] && s2[z] && s1[z] == s2[z] && z < (n - 1))
		z++;
	return ((unsigned char)s1[z] - (unsigned char)s2[z]);
}

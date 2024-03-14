/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:45:16 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/06 12:12:02 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destd;
	char	*srcd;

	destd = (char *)dest;
	srcd = (char *)src;
	if (destd < srcd)
	{
		while (n)
		{
			*destd = *srcd;
			destd++;
			srcd++;
			n--;
		}
	}
	else if (destd > srcd)
	{
		while (n)
		{
			n--;
			destd[n] = srcd[n];
		}
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:28:14 by mbartsch          #+#    #+#             */
/*   Updated: 2023/07/03 16:28:16 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	swap_buff(char *buffer, int len)
{
	int	z;
	int	sp;

	if (buffer[0] == '-')
		z = 1;
	else
		z = 0;
	while (len > z)
	{
		len--;
		sp = buffer[z];
		buffer[z] = buffer[len];
		buffer[len] = sp;
		z++;
	}
}

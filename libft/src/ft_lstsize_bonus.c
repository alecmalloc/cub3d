/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:33:55 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/12 14:15:51 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		nodes;

	if (!(lst))
		return (0);
	nodes = 1;
	node = lst;
	while (node->next)
	{
		nodes++;
		node = node->next;
	}
	return (nodes);
}

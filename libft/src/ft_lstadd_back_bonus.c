/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:37:56 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/13 15:28:58 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **llst, t_list *new)
{
	t_list	*node;

	if (llst == NULL || new == NULL)
		return ;
	if (*llst == NULL)
		*llst = new;
	else
	{
		node = *llst;
		while (node->next)
			node = node->next;
		node->next = new;
	}
}

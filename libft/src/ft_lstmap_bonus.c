/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:47:02 by mbartsch          #+#    #+#             */
/*   Updated: 2022/12/12 17:07:05 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	node = ft_lstnew(f(lst->content));
	if (!(node))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_lst = node;
	lst = lst->next;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!(node))
		{
			ft_lstclear(&new_lst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, node);
	}
	return (new_lst);
}

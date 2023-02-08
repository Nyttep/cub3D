/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:02:52 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/01 21:07:39 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	t_list	*current;

	first = malloc(sizeof(t_list));
	if (!first)
		return (NULL);
	first->content = f(lst->content);
	lst = lst->next;
	current = first;
	while (lst)
	{
		new = malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		current->next = new;
		current = current->next;
		current->content = f(lst->content);
		lst = lst->next;
	}
	current->next = NULL;
	return (first);
}

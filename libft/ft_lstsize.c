/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:03:04 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/01 21:07:49 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ret;
	t_list	*begin;

	begin = lst;
	ret = 0;
	while (lst)
	{
		ret++;
		lst = lst->next;
	}
	lst = begin;
	return (ret);
}

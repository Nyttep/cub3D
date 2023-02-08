/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 23:06:39 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/01 21:03:20 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*tmp1;
	char		*tmp2;
	int			i;

	i = -1;
	tmp1 = src;
	tmp2 = dest;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		i = n;
		while (i)
		{
			i--;
			tmp2[i] = tmp1[i];
		}
	}
	else
		while ((size_t)++i < n)
			tmp2[i] = tmp1[i];
	return (dest);
}

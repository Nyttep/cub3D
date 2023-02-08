/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:32:01 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/01 21:03:10 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmps;
	unsigned char		tmpc;
	size_t				i;

	tmps = s;
	tmpc = c;
	i = 0;
	while (i < n)
	{
		if (tmps[i] == tmpc)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

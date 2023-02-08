/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:32:06 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/01 21:03:13 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;
	size_t				i;
	int					res;

	i = 0;
	res = 0;
	tmp1 = (const unsigned char *)s1;
	tmp2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
			return (res = tmp1[i] - tmp2[i]);
		i++;
	}
	return (res);
}

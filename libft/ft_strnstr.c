/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:33:53 by pdubois           #+#    #+#             */
/*   Updated: 2021/11/26 06:17:55 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		while (big[i + j] == little[j] && big[i + j] && little[j])
		{
			if (little[j + 1] == 0 && i + j < len)
				return ((char *) &big[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

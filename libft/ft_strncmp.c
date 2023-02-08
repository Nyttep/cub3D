/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:33:49 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/03 18:13:27 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*s1, const char	*s2, size_t	n)
{
	int		res;
	size_t	i;

	i = 0;
	res = 0;
	while (i < n)
	{
		res = res + ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
		if (!(unsigned const char)s1[i] || !(unsigned const char)s2[i])
			return (res);
		i++;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:34:11 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/01 19:31:31 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty(void)
{
	char	*ret;

	ret = malloc(1);
	if (!ret)
		return (NULL);
	ret[0] = 0;
	return (ret);
}

static char	*ft_protec(char const	*s, unsigned int start, size_t len )
{
	char	*ret;

	if ((size_t)ft_strlen(s + start) < len)
	{
		ret = (char *) malloc(sizeof(char) * (ft_strlen(s + start) + 1));
		if (!ret)
			return (NULL);
		ret[ft_strlen(s + start)] = 0;
	}
	else
	{
		ret = (char *) malloc(sizeof(char) * (len + 1));
		if (!ret)
			return (NULL);
		ret[len] = 0;
	}
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (start >= (unsigned int)ft_strlen(s) || !len)
		return (ft_empty());
	ret = ft_protec(s, start, len);
	if (!ret)
		return (NULL);
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	return (ret);
}

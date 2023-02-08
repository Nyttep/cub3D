/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:34:03 by pdubois           #+#    #+#             */
/*   Updated: 2021/11/26 09:04:52 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_charset(char const c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_lenght_trimmed(char const *s1, char const *set)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (ft_is_in_charset(s1[i], set))
		i++;
	if (i == ft_strlen(s1))
		return (0);
	while (ft_is_in_charset(s1[ft_strlen(s1) - 1 - ret], set))
		ret++;
	return (ft_strlen(s1) - (ret + i));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		len;
	int		j;

	len = ft_lenght_trimmed(s1, set);
	i = 0;
	j = 0;
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = 0;
	while (ft_is_in_charset(s1[i], set) && s1[i])
		i++;
	while (len > 0)
	{
		ret[j] = s1[i];
		i++;
		j++;
		len--;
	}
	return (ret);
}

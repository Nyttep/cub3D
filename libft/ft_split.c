/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:33:07 by pdubois           #+#    #+#             */
/*   Updated: 2021/12/01 21:50:00 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char charset)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != charset)
		{
			ret++;
			while (s[i] != charset && s[i])
				i++;
		}
		else
			i++;
	}
	return (ret);
}

static char	*ft_strcpy(char const *s, int *i, int size)
{
	int		j;
	char	*ret;

	j = 0;
	ret = (char *) malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	while (j < size)
	{
		ret[j] = s[*i];
		*i = *i + 1;
		j++;
	}
	ret[j] = 0;
	return (ret);
}

static char	**ft_25_lines(int size)
{
	char	**ret;

	ret = (char **) malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = NULL;
	return (ret);
}

static char	**ft_free(char	**ret, int k)
{
	while (k >= 0)
	{
		free(ret[k]);
		k--;
	}
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char charset)
{
	char	**ret;
	int		i;	
	int		j;	
	int		k;	

	k = -1;
	i = 0;
	ret = ft_25_lines(ft_count_word(s, charset));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		if (s[i] != charset)
		{
			j = i;
			while (s[j] != charset && s[j])
				j++;
			ret[++k] = ft_strcpy(s, &i, j - i);
			if (!ret[k])
				return (ft_free(ret, k));
		}
		else
			i++;
	}
	return (ret);
}

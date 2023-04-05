/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:05:41 by pdubois           #+#    #+#             */
/*   Updated: 2023/04/05 15:45:43 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*ft_realloc_strs(void *ptr, size_t size)
{
	char	**tmp;
	char	**ret;
	int		i;

	tmp = (char **)ptr;
	i = 0;
	ret = malloc(size);
	if (!ret)
	{
		free(ptr);
		return ((void *) NULL);
	}
	ft_bzero(ret, size);
	while (tmp[i])
	{
		ret[i] = tmp[i];
		i++;
	}
	free(ptr);
	return (ret);
}

int	ft_max_len(int nb_line, char **strs)
{
	int	i;
	int	max_len;

	max_len = 0;
	i = 0;
	while (i < nb_line - 2)
	{
		if (ft_strlen(strs[i]) > max_len)
			max_len = ft_strlen(strs[i]);
		i++;
	}
	max_len += 2;
	return (max_len);
}

void	ft_init_set(char *set[6])
{
	set[0] = "NO ";
	set[1] = "EA ";
	set[2] = "SO ";
	set[3] = "WE ";
	set[4] = "F ";
	set[5] = "C ";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:46:14 by pdubois           #+#    #+#             */
/*   Updated: 2022/02/21 01:34:23 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

int	ft_is_newline_gnl(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_gnl(char	*s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_kinda_strcat_gnl(char	*s, char	*init)
{
	char	*ret;
	int		len_s;
	int		len_init;
	int		i;
	int		j;

	i = -1;
	j = 0;
	len_s = ft_strlen_gnl(s);
	len_init = ft_strlen_gnl(init);
	ret = malloc(len_init + len_s + 1);
	ret[len_init + len_s] = 0;
	while (++i < len_init)
		ret[i] = init[i];
	j = i;
	i = 0;
	free(init);
	while (i < len_s && s[i] != '\n')
	{
		ret[i + j] = s[i];
		i++;
	}
	if (s[i] == '\n')
		ret[i + j] = '\n';
	return (ret);
}

void	ft_get_reste_gnl(char	*s, char	*reste, int read_return)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == 0)
		i = -1;
	if (read_return <= 0)
		return ;
	while (s[++i])
		reste[j++] = s[i];
	reste[j] = 0;
}

char	*ft_cpy_and_rst_reste_gnl(char	*ret, char	*reste)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (reste[i] && reste[i] != '\n')
	{
		ret[i] = reste[i];
		i++;
	}
	if (reste[i] == '\n')
	{
		ret[i] = reste[i];
		i++;
	}
	ret[i] = 0;
	while (reste[i])
	{
		reste[j] = reste[i];
		j++;
		i++;
	}
	reste[j] = 0;
	return (ret);
}

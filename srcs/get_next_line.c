/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:52:34 by pdubois           #+#    #+#             */
/*   Updated: 2022/02/21 01:34:10 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

char	*ft_free(char *ret, char *s)
{
	free(ret);
	free(s);
	return (NULL);
}

void	ft_init_gnl(char	**s, char	**ret, int	*read_return, char	*reste)
{
	*s = malloc(BUFFER_SIZE + 1);
	if (!(*s))
		return ;
	*ret = malloc(BUFFER_SIZE + 1);
	if (!(*ret))
	{
		free(s);
		return ;
	}
	*s[0] = 0;
	*ret[0] = 0;
	*ret = ft_cpy_and_rst_reste_gnl(*ret, reste);
	*read_return = 0;
}

char	*get_next_line(int fd)
{
	char		*s;
	char		*ret;
	static char	reste[BUFFER_SIZE];
	int			found;
	int			read_return;

	ft_init_gnl(&s, &ret, &read_return, reste);
	if (!ret || !s)
		return (NULL);
	found = ft_is_newline_gnl(ret);
	if (!found)
		read_return = read(fd, s, BUFFER_SIZE);
	while (!found && read_return > 0)
	{
		s[read_return] = 0;
		found = ft_is_newline_gnl(s);
		ret = ft_kinda_strcat_gnl(s, ret);
		if (!found)
			read_return = read(fd, s, BUFFER_SIZE);
	}
	if (read_return <= 0 && !ft_strlen_gnl(ret))
		return (ft_free(ret, s));
	ft_get_reste_gnl(s, reste, read_return);
	free(s);
	return (ret);
}

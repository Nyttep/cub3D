/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:54:26 by pdubois           #+#    #+#             */
/*   Updated: 2023/04/03 18:06:29 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_skip_spaces(char *s)
{
	while (*s == ' ' && *s)
		s++;
	return (s);
}

void	ft_trim_end(char *s)
{
	int	end;

	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n')
		end--;
	s[end + 1] = 0;
}

bool	ft_is_unfinished(bool state[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (state[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_format_path(char *buff)
{
	int	i;

	i = 0;
	buff = ft_skip_spaces(buff);
	while (ft_isalpha(buff[i]))
		i++;
	buff = ft_skip_spaces(buff + i);
	ft_trim_end(buff);
	return ((buff));
}

int	ft_is_valid_char_map(char c)
{
	if (c == ' ')
		return (1);
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:54:26 by pdubois           #+#    #+#             */
/*   Updated: 2023/04/02 17:50:34 by pdubois          ###   ########.fr       */
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

int	ft_max_length(char **strs)
{
	int	ret;
	int	tmp;
	int	i;

	i = 0;
	tmp = 0;
	ret = 0;
	while (strs[i])
	{
		tmp = ft_strlen(strs[i]);
		if (tmp > ret)
			ret = tmp;
		i++;
	}
	return (ret);
}

void	*ft_realloc_strs(void *ptr, size_t size)
{
	char	**tmp;
	char	**ret;
	int		i;

	tmp = (char **)ptr;
	i = 0;
	ret = malloc(size);
	if (!ret)
		return ((void *) NULL);
	ft_bzero(ret, size);
	while (tmp[i])
	{
		ret[i] = tmp[i];
		i++;
	}
	free(ptr);
	return (ret);
}

int	ft_hex_to_int(char *nb)
{
	int ret;
	int	base;
	int	i;

	ret = 0;
	base = 1;
	i = ft_strlen(nb);
	while (i >= 0)
	{
		if(nb[i] >= '0' && nb[i] <= '9')
		{
			ret += (nb[i] - 48) * base;
			base *= 16;
		}
		else if(nb[i] >= 'A' && nb[i] <= 'F')
		{
			ret += (nb[i] - 55) * base;
			base *= 16;
		}
		else if(nb[i] >= 'a' && nb[i] <= 'f')
		{
			ret += (nb[i] - 87) * base;
			base *= 16;
		}
		i--;
	}
	return (ret);
}

char	*ft_int_to_hex(int	nb)
{
	int	remain;
	int	j;
	char *ret;

	j = 1;
	ret = malloc(sizeof(char) * (3));
	ft_bzero(ret, (sizeof(char) * 3));
	ret[0] = '0';
	ret[1] = '0';
	while (nb != 0)
	{
		remain = nb % 16;
		if (remain < 10)
			ret[j--] = 48 + remain;
		else
			ret[j--] = 55 + remain;
		nb = nb / 16;
	}
	return (ret);
}

int	ft_convert_rgb_to_int(int rgb[3])
{
	char	*rgb_hex[3];
	char	*hex;
	char	*tmp;
	int		ret;

	rgb_hex[0] = ft_int_to_hex(rgb[0]);
	rgb_hex[1] = ft_int_to_hex(rgb[1]);
	rgb_hex[2] = ft_int_to_hex(rgb[2]);
	tmp = ft_strjoin(rgb_hex[0], rgb_hex[1]);
	hex = ft_strjoin(tmp, rgb_hex[2]);
	free(tmp);
	free(rgb_hex[0]);
	free(rgb_hex[1]);
	free(rgb_hex[2]);
	ret = ft_hex_to_int(hex);
	free(hex);
	return (ret);
}

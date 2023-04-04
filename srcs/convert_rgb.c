/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:03:27 by pdubois           #+#    #+#             */
/*   Updated: 2023/04/04 15:53:41 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_hex_to_int(char *nb)
{
	int	ret;
	int	base;
	int	i;

	ret = 0;
	base = 1;
	i = ft_strlen(nb);
	while (i >= 0)
	{
		if (nb[i] >= '0' && nb[i] <= '9')
		{
			ret += (nb[i] - 48) * base;
			base *= 16;
		}
		else if (nb[i] >= 'A' && nb[i] <= 'F')
		{
			ret += (nb[i] - 55) * base;
			base *= 16;
		}
		i--;
	}
	return (ret);
}

char	*ft_int_to_hex(int nb)
{
	int		remain;
	int		j;
	char	*ret;

	j = 1;
	ret = malloc(sizeof(char) * (3));
	if (!ret)
		return (NULL);
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

int	ft_free_convert(char *rgb_hex[3], char *tmp)
{
	if (rgb_hex[0])
		free(rgb_hex[0]);
	if (rgb_hex[1])
		free(rgb_hex[1]);
	if (rgb_hex[2])
		free(rgb_hex[2]);
	if (tmp)
		free(tmp);
	return (0);
}

void	ft_init_rbg_hex(char *rgb_hex[3], int rgb[3])
{
	rgb_hex[1] = NULL;
	rgb_hex[2] = NULL;
	rgb_hex[0] = ft_int_to_hex(rgb[0]);
	rgb_hex[1] = ft_int_to_hex(rgb[1]);
	rgb_hex[2] = ft_int_to_hex(rgb[2]);
}

int	ft_convert_rgb_to_int(int rgb[3])
{
	char	*rgb_hex[3];
	char	*hex;
	char	*tmp;
	int		ret;

	ft_init_rbg_hex(rgb_hex, rgb);
	tmp = NULL;
	if (!rgb_hex[0])
		return (ft_free_convert(rgb_hex, tmp));
	if (!rgb_hex[1])
		return (ft_free_convert(rgb_hex, tmp));
	if (!rgb_hex[2])
		return (ft_free_convert(rgb_hex, tmp));
	tmp = ft_strjoin(rgb_hex[0], rgb_hex[1]);
	if (!tmp)
		return (ft_free_convert(rgb_hex, tmp));
	hex = ft_strjoin(tmp, rgb_hex[2]);
	ft_free_convert(rgb_hex, tmp);
	if (!hex)
		return (0);
	ret = ft_hex_to_int(hex);
	free(hex);
	return (ret);
}

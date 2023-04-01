/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:44:38 by paul              #+#    #+#             */
/*   Updated: 2023/04/01 16:22:58 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_basic(int ac, char **av)
{
	int	len_av;

	if (ac != 2)
		ft_error(NULL, "too many or no arguments");
	len_av = ft_strlen(av[1]);
	if (ft_strcmp(av[1] + (len_av - 4), ".cub") != 0)
		ft_error(NULL, "The file is not a .cub");
	if (len_av == 4)
		ft_error(NULL, "The file is not a .cub");
}

int	ft_check_rbgformat_afterdigits(char *str, int i, int k)
{
	if (str[i] != ',' || k == 3)
	{
		if (k == 3 && str[i] == ' ')
			if (*ft_skip_spaces(str + i) == '\0')
				return (0);
		if (k == 3 && str[i] == '\0')
			return (0);
		return (1);
	}
	return (0);
}

int	ft_check_rgbformat(char *str, int i)
{
	int	j;
	int	k;

	k = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '+' || str[i] == '-')
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (1);
		while (ft_isdigit(str[i]))
		{
			j++;
			i++;
		}
		if (j == 0)
			return (1);
		k++;
		if (ft_check_rbgformat_afterdigits(str, i, k))
			return (1);
		i++;
	}
	if (k != 3)
		return (1);
	return (0);
}

int	ft_check_rgb(char *str)
{
	int	i;

	i = 0;
	if (ft_check_rgbformat(str, i))
		return (1);
	while (i < 3)
	{
		if (ft_atoi(str) < 0 || ft_atoi(str) > 255)
			return (1);
		while (*str != ',' && *str)
			str++;
		str++;
		i++;
	}
	return (0);
}

void	ft_check_map(t_game *game)
{
	int		i;
	int		j;
	char	c;
	
	i = 1;
	while (i < ft_strslen(game->map) - 1)
	{
		j = 1;
		while (j < ft_strlen(game->map[i]) - 1)
		{
			c = game->map[i][j];
			if (!ft_is_valid_char_map(c))
				ft_error(game, "The map is not valid");
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (game->map[i][j - 1] == ' ')
					ft_error(game, "The map is not valid");
				if (game->map[i][j + 1] == ' ')
					ft_error(game, "The map is not valid");
				if (game->map[i - 1][j] == ' ')
					ft_error(game, "The map is not valid");
				if (game->map[i + 1][j] == ' ')
					ft_error(game, "The map is not valid");
			}
			j++;
		}
		i++;
	}
}

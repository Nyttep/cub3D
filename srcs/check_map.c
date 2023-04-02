/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:54:58 by pdubois           #+#    #+#             */
/*   Updated: 2023/04/02 17:55:27 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_if_spaces_around(t_game *game, int i, int j)
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
				ft_check_if_spaces_around(game, i, j);
			j++;
		}
		i++;
	}
}

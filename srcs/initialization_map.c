/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:55:03 by pdubois           #+#    #+#             */
/*   Updated: 2023/04/04 15:21:09 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_fill_map(t_game *game, char **srcs, int max_len)
{
	int	tab[5];

	ft_bzero(tab, (sizeof(int) * 5));
	while (srcs[tab[0]])
	{
		tab[2] = ft_strlen(srcs[tab[0]]) - 2;
		if (srcs[tab[0]][ft_strlen(srcs[tab[0]]) - 1] != '\n')
			tab[2] = ft_strlen(srcs[tab[0]]) - 1;
		tab[4] = tab[2] + 1;
		tab[3] = 0;
		game->map[tab[1]][tab[3]++] = ' ';
		while (tab[2] >= 0 && tab[3] < max_len - 1)
		{
			if ((tab[1] == 0 || tab[1] == ft_strslen(srcs) + 1)
				|| (tab[3] < (max_len - tab[4] - 1)))
				game->map[tab[1]][tab[3]++] = ' ';
			else
				game->map[tab[1]][tab[3]++] = srcs[tab[0]][tab[2]--];
		}
		while (tab[3] < max_len)
			game->map[tab[1]][tab[3]++] = ' ';
		if (tab[1] != 0 && tab[1] != ft_strslen(srcs))
			tab[0]++;
		tab[1]++;
	}
}

char	**ft_pre_init_map(t_game *game, int fd, char *buff)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char *) * 20);
	if (!ret)
	{
		free(buff);
		ft_error(game, NULL);
	}
	ft_bzero(ret, (sizeof(char *) * 20));
	while (buff && ft_skip_spaces(buff)[0] == '\n')
	{
		free(buff);
		buff = get_next_line(fd);
	}
	if (!buff || !ft_is_valid_char_map(ft_skip_spaces(buff)[0]))
	{
		free(ret);
		ft_error(game, "The .cub does not conform");
	}
	while (buff && ft_skip_spaces(buff)[0] != '\n')
	{
		if (i % 20 == 19)
			ret = ft_realloc_strs(ret, (sizeof(char *) * (i + 21)));
		if (!ret)
		{
			free(buff);
			ft_error(game, NULL);
		}
		ret[i++] = buff;
		buff = get_next_line(fd);
	}
	return (ret);
}

void	ft_init_map(t_game *game, int fd, char *buff)
{
	char	**tmp;
	int		nb_line;
	int		i;
	int		max_len;

	tmp = ft_pre_init_map(game, fd, buff);
	nb_line = ft_strslen(tmp) + 2;
	game->map = malloc(sizeof(char *) * (nb_line + 1));
	if (!game->map)
	{
		ft_free_strs(tmp);
		ft_error(game, NULL);
	}
	ft_bzero(game->map, (sizeof(char *) * (nb_line + 1)));
	max_len = ft_find_max_len(nb_line, tmp);
	i = 0;
	while (i < nb_line)
	{
		game->map[i] = malloc(sizeof(char) * (max_len + 1));
		if (!game->map[i])
		{
			ft_free_strs(tmp);
			ft_error(game, NULL);
		}
		ft_bzero(game->map[i], (sizeof(char) * (max_len + 1)));
		i++;
	}
	ft_fill_map(game, tmp, max_len);
	ft_free_strs(tmp);
}

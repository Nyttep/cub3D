/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:09:12 by pdubois           #+#    #+#             */
/*   Updated: 2023/02/09 16:02:3 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_fill_map(t_game *game, char **srcs, int max_len)
{
	int	i;
	int	l;
	int	j;
	int	k;

	i = 0;
	l = 0;
	while (srcs[i])
	{
		j = 0;
		k = 0;
		game->map[l][k++] = ' ';
		while (srcs[i][j] && srcs[i][j] != '\n')
		{
			if (l == 0 || l == ft_strslen(srcs) + 1)
				game->map[l][k] = ' ';
			else
				game->map[l][k] = srcs[i][j];
			j++;
			k++;
		}
		while (k < max_len - 1)
			game->map[l][k++] = ' ';
		if (l != 0 && l != ft_strslen(srcs))
			i++;
		l++;
	}
}

char	**ft_pre_init_map(t_game *game, int fd, char *buff)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char*) * 20);
	if (!ret)
		ft_error(game, NULL);
	ft_bzero(ret, (sizeof(char*) * 20));
	while (buff && ft_skip_spaces(buff)[0] == '\n')
	{
		free(buff);
		buff = get_next_line(fd);
	}
	if (!buff || !ft_is_valid_char_map(ft_skip_spaces(buff)[0]))
		ft_error(game, "The .cub does not conform");
	while (buff && ft_skip_spaces(buff)[0] != '\n')
	{
		if (i % 20 == 19)
		{
			ft_printf("i = %d\n", i);
			ret = ft_realloc_strs(ret, (sizeof(char*) * (i + 21)));
		}
		ret[i] = buff;
		i++;
		if (!ret)
			ft_error(game, NULL);
		buff = get_next_line(fd);
	}
	return (ret);
}

void	ft_display_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("|%s|\n", map[i]);
		i++;
	}
}

void	ft_init_map(t_game *game, int fd, char *buff)
{
	char	**tmp;
	int		nb_line;
	int		i;
	int		max_len;

	max_len = 0;
	i = 0;
	tmp = ft_pre_init_map(game, fd, buff);
	nb_line = ft_strslen(tmp) + 2;
	game->map = malloc(sizeof(char*) * (nb_line + 1));
	if (!game->map)
		ft_error(game, NULL);
	ft_bzero(game->map, (sizeof(char*) * (nb_line + 1)));
	while (i < nb_line - 2)
	{
		if (ft_strlen(tmp[i]) > max_len)
			max_len = ft_strlen(tmp[i]);
		i++;
	}
	max_len += 2;
	i = 0;
	while (i < nb_line)
	{
		game->map[i] = malloc(sizeof(char) * (max_len));
		if (!game->map[i])
			ft_error(game, NULL);
		ft_bzero(game->map[i], (sizeof(char) * (max_len)));
		i++;
	}
	ft_fill_map(game, tmp, max_len);
	ft_free_strs(tmp);
}

void	ft_init(t_game *game, char **av)
{
	int	fd;
	char *buff;

	ft_bzero(game, sizeof(game));
	game->mlx = mlx_init();
	if (!(game->mlx))
		ft_error(game, NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error(game, NULL);
	buff = ft_init_ressources(game, fd); // does not handle spaces well yet
	ft_init_map(game, fd, buff);
	ft_display_map(game->map);
	ft_check_map(game);
	// check map & end of .cub
	close(fd);
}

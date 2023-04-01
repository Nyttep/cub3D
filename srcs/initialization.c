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

// void	ft_fill_map()

char	**ft_pre_init_map(t_game *game, int fd, char *buff)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char*) * 20);
	ft_bzero(ret, sizeof(ret));
	while (buff && ft_skip_spaces(buff)[0] == '\n')
	{
		buff = get_next_line(fd);
		free(buff);
		buff = get_next_line(fd);
	}
	if (!buff || !ft_is_valid_char_map(ft_skip_spaces(buff)[0]))
		ft_error(game, "The .cub does not conform");
	while (buff && ft_skip_spaces(buff)[0] != '\n')
	{
		ret[i] = buff;
		i++;
		if (i % 20 == 19)
			ft_realloc(ret, (sizeof(char*) * (i + 20)));
		buff = get_next_line(fd);
	}
	return (ret);
}

void	ft_fill_str(char *to, char *from, int length_max)
{
	int	j;

	j = 0;
	while (j < length_max)
	{
		if (from[j] == '\n')
			while (j < length_max)
				to[j++] = ' ';
		else
			to[j] =  from[j];
		j++;
	}	
}

void	ft_init_map(t_game *game, int fd, char *buff)
{
	char	**tmp;
	int		nb_line;
	int		length_max;
	int		i;

	i = 0;
	tmp = ft_pre_init_map(game, fd, buff);
	nb_line = ft_strslen(tmp);
	length_max = ft_max_length(tmp);
	game->map = malloc(sizeof(char*) * (nb_line));
	while (i < nb_line)
	{
		game->map[i] = malloc(sizeof(char) * (length_max + 2));
		game->map[i][length_max] = 0;
		ft_fill_str(game->map[i], tmp[i], length_max);
		free(tmp[i])
		i++;
	}
	free(tmp);
}

void	ft_init(t_game *game, char **av)
{
	int	fd;
	char *buff;

	ft_bzero(game, sizeof(game));
	// game->mlx = mlx_init();
	// if (!(game->mlx))
	// 	ft_error(game, NULL); TEMPORAIRE SANS LA MLX
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error(game, NULL);
	buff = ft_init_ressources(game, fd); // does not handle spaces well yet
	ft_init_map(game, fd, buff);
	ft_check_map(game);
	// check map & end of .cub
	close(fd);
}

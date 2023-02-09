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

// char	**ft_pre_init_map(t_game *game, int fd, char *buff)
// {
// 	char	**ret;
// 	int		i;

// 	i = 0;
// 	ret = malloc(sizeof(char*) * 20);
// 	ft_bzero(ret, sizeof(ret));
// 	while (buff && ft_skip_spaces(buff)[0] == '\n')
// 	{
// 		buff = get_next_line(fd);
// 		free(buff);
// 		buff = get_next_line(fd);
// 	}
// 	if (!buff || !ft_is_valid_char_map(ft_skip_spaces(buff)[0]))
// 		ft_error(game, "The .cub does not conform");
// 	while (buff && ft_skip_spaces(buff)[0] != '\n')
// 	{
// 		ret[i] = buff;
// 		i++;
// 		if (i % 20 == 19)
// 			ft_realloc(ret, (sizeof(char*) * (i + 20)));
// 		buff = get_next_line(fd);
// 	}
// 	return (ret);
// }

// void	ft_init_map(t_game *game, int fd, char *buff)
// {
// 	char	**tmp;
// 	int		nb_line;

// 	nb_line = ft_strslen(tmp);
// 	tmp = ft_pre_init_map(game, fd, buff);
// 	game->map = malloc(sizeof(char*) * (nb_line);
// 	while (nb_line = )
// }

void	ft_init(t_game *game, char **av)
{
	int	fd;
	char *buff;

	(void)buff;
	ft_bzero(game, sizeof(game));
	game->mlx = mlx_init();
	if (!(game->mlx))
		ft_error(game, NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error(game, NULL);
	buff = ft_init_ressources(game, fd); // does not handle spaces well yet
	// ft_init_map(game, fd, buff);
	// check map & end of .cub
	close(fd);
}

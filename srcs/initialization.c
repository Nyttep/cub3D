/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:09:12 by pdubois           #+#    #+#             */
/*   Updated: 2023/04/02 18:26:31 by pdubois          ###   ########.fr       */
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
		ft_error(game, NULL);
	ft_bzero(ret, (sizeof(char *) * 20));
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
			ret = ft_realloc_strs(ret, (sizeof(char *) * (i + 21)));
		}
		if (!ret)
			ft_error(game, NULL);
		ret[i] = buff;
		i++;
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
	game->map = malloc(sizeof(char *) * (nb_line + 1));
	if (!game->map)
		ft_error(game, NULL);
	ft_bzero(game->map, (sizeof(char *) * (nb_line + 1)));
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
		game->map[i] = malloc(sizeof(char) * (max_len + 1));
		if (!game->map[i])
			ft_error(game, NULL);
		ft_bzero(game->map[i], (sizeof(char) * (max_len + 1)));
		i++;
	}
	ft_fill_map(game, tmp, max_len);
	ft_free_strs(tmp);
}

void	ft_init_direction_2(t_game *game)
{
	if (game->direction == 'S')
	{
		game->ray.dirx = 0;
		game->ray.diry = 1;
		game->ray.planx = 0.66;
		game->ray.plany = 0;
	}
	else if (game->direction == 'N')
	{
		game->ray.dirx = 0;
		game->ray.diry = -1;
		game->ray.planx = -0.66;
		game->ray.plany = 0;
	}
}

void	ft_init_direction(t_game *game)
{
	if (game->direction == 'E')
	{
		game->ray.dirx = -1;
		game->ray.diry = 0;
		game->ray.planx = 0;
		game->ray.plany = 0.66;
	}
	else if (game->direction == 'W')
	{
		game->ray.dirx = 1;
		game->ray.diry = 0;
		game->ray.planx = 0;
		game->ray.plany = -0.66;
	}
	else
		ft_init_direction_2(game);
}

void	ft_init_player(t_game *game)
{
	int	i;
	int	y;
	int	nb;

	i = 0;
	nb = 0;
	while (game->map[i] != NULL)
	{
		y = -1;
		while (game->map[i][++y] != '\0')
		{
			if (game->map[i][y] == 'N' || game->map[i][y] == 'S'
				|| game->map[i][y] == 'E' || game->map[i][y] == 'W')
			{
				nb++;
				game->direction = game->map[i][y];
				game->x = y++;
				game->y = i;
			}
		}
		i++;
	}
	if (nb != 1)
		ft_error(game, "too much or no player found");
	ft_init_direction(game);
}

void	ft_check_after_map(t_game *game, int fd, char *buff)
{
	buff = get_next_line(fd);
	while (buff)
	{
		if (buff[0] != '\n')
		{
			free(buff);
			ft_error(game, "there should not be anything after the map");
		}
		free(buff);
		buff = get_next_line(fd);
	}
}

void	ft_init(t_game *game, char **av)
{
	int		fd;
	char	*buff;

	ft_bzero(game, sizeof(game));
	game->mlx = mlx_init();
	if (!(game->mlx))
		ft_error(game, NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error(game, NULL);
	buff = ft_init_ressources(game, fd);
	ft_init_map(game, fd, buff);
	ft_display_map(game->map);
	ft_check_map(game);
	ft_init_player(game);
	ft_check_after_map(game, fd, buff);
	close(fd);
}

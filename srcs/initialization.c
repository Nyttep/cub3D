/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:09:12 by pdubois           #+#    #+#             */
/*   Updated: 2023/04/03 18:22:37 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	ft_init(t_game *game, char **av)
{
	char	*buff;

	ft_bzero(game, sizeof(game));
	game->mlx = mlx_init();
	if (!(game->mlx))
		ft_error(game, NULL);
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		ft_error(game, NULL);
	buff = ft_init_ressources(game, game->fd);
	ft_init_map(game, game->fd, buff);
	ft_display_map(game->map);
	ft_check_map(game);
	ft_init_player(game);
	ft_check_after_map(game, game->fd, buff);
	if (close(game->fd) == -1)
		ft_error(game, NULL);
	game->fd = 0;
}

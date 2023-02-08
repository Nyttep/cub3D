/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:09:12 by pdubois           #+#    #+#             */
/*   Updated: 2023/02/08 16:35:12 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	ft_init_map(char **av, t_game *game)
// {

// }

void	ft_init(t_game *game, char **av)
{
	int	fd;

	ft_bzero(game, sizeof(game));
	game->mlx = mlx_init();
	if (!(game->mlx))
		ft_error(game, NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error(game, NULL);
	ft_init_ressources(game, fd);
	// ft_init_map(av[1], game);
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:30 by pdubois           #+#    #+#             */
/*   Updated: 2023/02/09 18:28:25 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_game	*game;

	ft_check_basic(ac, av);
	game = malloc(sizeof(t_game));
	if (!game)
		ft_error(game, NULL);
	ft_init(game, av);
	tests_raycasting(game);
}

void	tests_raycasting(t_game	*game)
{
	game->win = mlx_new_window(game->mlx, 1920, 1080, "Hello world!");
	game->img = mlx_new_image(game->mlx, 1920, 1080);
	// game->width = ;
	// game->height = ;

	// mlx_key_hook(game->win, , );
	// mlx_key_hook(game->win, , );
	// mlx_key_hook(game->win, , );
	// mlx_key_hook(game->win, , );
	mlx_loop(game->mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:56:46 by aradice           #+#    #+#             */
/*   Updated: 2023/04/02 18:16:58 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_coordinate_on_texture(t_game *game)
{
	game->ray.texx = (int)(game->ray.wallx * (double)game->texwidth);
	if (game->ray.side == 0 && game->ray.raydirx > 0)
		game->ray.texx = game->texwidth - game->ray.texx - 1;
	if (game->ray.side == 1 && game->ray.raydiry < 0)
		game->ray.texx = game->texwidth - game->ray.texx - 1;
}

void	ft_player_middle_box(t_game *game)
{
	game->ray.posx = (double)game->x + 0.5;
	game->ray.posy = (double)game->y + 0.5;
}

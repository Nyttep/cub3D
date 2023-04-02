/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:51:04 by aradice           #+#    #+#             */
/*   Updated: 2023/04/02 17:55:24 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rotate_left(int keycode, t_game *game)
{
	if (keycode == KEY_RIGHT)
	{
		game->ray.dirx = game->ray.dirx * cos(-game->ray.rotspeed)
			- game->ray.diry * sin(-game->ray.rotspeed);
		game->ray.diry = game->ray.dirx * sin(-game->ray.rotspeed)
			+ game->ray.diry * cos(-game->ray.rotspeed);
		game->ray.planx = game->ray.planx * cos(-game->ray.rotspeed)
			- game->ray.plany * sin(-game->ray.rotspeed);
		game->ray.plany = game->ray.planx * sin(-game->ray.rotspeed)
			+ game->ray.plany * cos(-game->ray.rotspeed);
	}
}

void	ft_rotate_right(int keycode, t_game *game)
{
	if (keycode == KEY_LEFT)
	{
		game->ray.dirx = game->ray.dirx * cos(game->ray.rotspeed)
			- game->ray.diry * sin(game->ray.rotspeed);
		game->ray.diry = game->ray.dirx * sin(game->ray.rotspeed)
			+ game->ray.diry * cos(game->ray.rotspeed);
		game->ray.planx = game->ray.planx * cos(game->ray.rotspeed)
			- game->ray.plany * sin(game->ray.rotspeed);
		game->ray.plany = game->ray.planx * sin(game->ray.rotspeed)
			+ game->ray.plany * cos(game->ray.rotspeed);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:51:04 by aradice           #+#    #+#             */
/*   Updated: 2023/04/04 18:40:24 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rotate_right(int keycode, t_game *game)
{
	double	olddirx;
	double	oldplanx;

	if (keycode == KEY_RIGHT)
	{
		olddirx = game->ray.dirx;
		oldplanx = game->ray.planx;
		game->ray.dirx = game->ray.dirx * cos(-game->ray.rotspeed)
			- game->ray.diry * sin(-game->ray.rotspeed);
		game->ray.diry = olddirx * sin(-game->ray.rotspeed)
			+ game->ray.diry * cos(-game->ray.rotspeed);
		game->ray.planx = game->ray.planx * cos(-game->ray.rotspeed)
			- game->ray.plany * sin(-game->ray.rotspeed);
		game->ray.plany = oldplanx * sin(-game->ray.rotspeed)
			+ game->ray.plany * cos(-game->ray.rotspeed);
	}
}

void	ft_rotate_left(int keycode, t_game *game)
{
	double	olddirx;
	double	oldplanx;

	if (keycode == KEY_LEFT)
	{
		olddirx = game->ray.dirx;
		oldplanx = game->ray.planx;
		game->ray.dirx = game->ray.dirx * cos(game->ray.rotspeed)
			- game->ray.diry * sin(game->ray.rotspeed);
		game->ray.diry = olddirx * sin(game->ray.rotspeed)
			+ game->ray.diry * cos(game->ray.rotspeed);
		game->ray.planx = game->ray.planx * cos(game->ray.rotspeed)
			- game->ray.plany * sin(game->ray.rotspeed);
		game->ray.plany = oldplanx * sin(game->ray.rotspeed)
			+ game->ray.plany * cos(game->ray.rotspeed);
	}
}

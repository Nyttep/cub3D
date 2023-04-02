/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:51:04 by aradice           #+#    #+#             */
/*   Updated: 2023/04/02 17:55:19 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_up(int keycode, t_game *game)
{
	if (keycode == 'w')
	{
		if (game->map[(int)(game->ray.posy)][(int)(game->ray.posx
			+ game->ray.dirx * game->ray.movespeed)] != '1')
			game->ray.posx += game->ray.dirx * game->ray.movespeed;
		if (game->map[(int)(game->ray.posy + game->ray.diry
				* game->ray.movespeed)][(int)(game->ray.posx)] != '1')
			game->ray.posy += game->ray.diry * game->ray.movespeed;
	}
}

void	ft_move_down(int keycode, t_game *game)
{
	if (keycode == 's')
	{
		if (game->map[(int)(game->ray.posy)][(int)(game->ray.posx
			- game->ray.dirx * game->ray.movespeed)] != '1')
			game->ray.posx -= game->ray.dirx * game->ray.movespeed;
		if (game->map[(int)(game->ray.posy - game->ray.diry
				* game->ray.movespeed)][(int)(game->ray.posx)] != '1')
			game->ray.posy -= game->ray.diry * game->ray.movespeed;
	}
}

void	ft_move_left(int keycode, t_game *game)
{
	if (keycode == 'a')
	{
		if (game->map[(int)(game->ray.posy)][(int)(game->ray.posx
			- game->ray.planx * game->ray.movespeed)] != '1')
			game->ray.posx -= game->ray.planx * game->ray.movespeed;
		if (game->map[(int)(game->ray.posy + game->ray.plany
				* game->ray.movespeed)][(int)(game->ray.posx)] != '1')
			game->ray.posy -= game->ray.plany * game->ray.movespeed;
	}
}

void	ft_move_right(int keycode, t_game *game)
{
	if (keycode == 'd')
	{
		if (game->map[(int)(game->ray.posy)][(int)(game->ray.posx
				+ game->ray.planx * game->ray.movespeed)] != '1')
			game->ray.posx += game->ray.planx * game->ray.movespeed;
		if (game->map[(int)(game->ray.posy - game->ray.plany
				* game->ray.movespeed)][(int)(game->ray.posx)] != '1')
			game->ray.posy += game->ray.plany * game->ray.movespeed;
	}
}

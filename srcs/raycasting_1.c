/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:56:46 by aradice           #+#    #+#             */
/*   Updated: 2023/04/02 18:19:21 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_raypos_and_direction(t_game *game, int i)
{
	game->ray.camerax = 2 * i / (double)WIN_WIDTH - 1;
	game->ray.raydirx = game->ray.dirx + game->ray.planx * game->ray.camerax;
	game->ray.raydiry = game->ray.diry + game->ray.plany * game->ray.camerax;
}

void	ft_which_box_i_am(t_game *game)
{
		game->ray.mapx = (int)game->ray.posx;
		game->ray.mapy = (int)game->ray.posy;
}

void	ft_lenght_ray(t_game *game)
{
	if (game->ray.raydirx != 0)
		game->ray.deltadistx = fabs(1 / game->ray.raydirx);
	else
		game->ray.deltadistx = 1e30;
	if (game->ray.raydiry != 0)
		game->ray.deltadisty = fabs(1 / game->ray.raydiry);
	else
	game->ray.deltadisty = 1e30;
}

void	ft_step_init_sidedist(t_game *game)
{
	if (game->ray.raydirx < 0)
	{
		game->ray.stepx = -1;
		game->ray.sidedistx = (game->ray.posx
				- game->ray.mapx) * game->ray.deltadistx;
	}
	else
	{
		game->ray.stepx = 1;
		game->ray.sidedistx = (game->ray.mapx + 1.0
				- game->ray.posx) * game->ray.deltadistx;
	}
	if (game->ray.raydiry < 0)
	{
		game->ray.stepy = -1;
		game->ray.sidedisty = (game->ray.posy
				- game->ray.mapy) * game->ray.deltadisty;
	}
	else
	{
		game->ray.stepy = 1;
		game->ray.sidedisty = (game->ray.mapy + 1.0
				- game->ray.posy) * game->ray.deltadisty;
	}
}

void	ft_hit_function(t_game *game)
{
	game->ray.hit = 0;
	while (game->ray.hit == 0)
	{
		if (game->ray.sidedistx < game->ray.sidedisty)
		{
			game->ray.sidedistx += game->ray.deltadistx;
			game->ray.mapx += game->ray.stepx;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedisty += game->ray.deltadisty;
			game->ray.mapy += game->ray.stepy;
			game->ray.side = 1;
		}
		if (game->map[game->ray.mapy][game->ray.mapx] == '1')
			game->ray.hit = 1;
	}
}

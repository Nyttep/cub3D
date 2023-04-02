/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:56:46 by aradice           #+#    #+#             */
/*   Updated: 2023/04/02 17:58:59 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_distance_prependicular_ray(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.perpwalldist = (game->ray.sidedistx - game->ray.deltadistx);
	else
		game->ray.perpwalldist = (game->ray.sidedisty - game->ray.deltadisty);
}

void	ft_heigth_line_to_draw(t_game *game)
{
	game->ray.lineheight = (int)(WIN_HEIGHT / game->ray.perpwalldist);
}

void	ft_lowest_and_highest_pixel(t_game *game)
{
	game->ray.drawstart = -game->ray.lineheight / 2 + WIN_HEIGHT / 2;
	if (game->ray.drawstart < 0)
		game->ray.drawstart = 0;
	game->ray.drawend = game->ray.lineheight / 2 + WIN_HEIGHT / 2;
	if (game->ray.drawend >= WIN_HEIGHT)
		game->ray.drawend = WIN_HEIGHT - 1;
}

void	ft_num_texture(t_game *game)
{
	if (game->ray.side == 1)
	{
		if (game->ray.raydiry < 0)
			game->ray.texnum = 0;
		else if (game->ray.raydiry > 0)
			game->ray.texnum = 1;
	}
	else if (game->ray.side == 0)
	{
		if (game->ray.raydirx < 0)
			game->ray.texnum = 2;
		else if (game->ray.raydirx > 0)
			game->ray.texnum = 3;
	}
}

void	ft_value_wallx_when_hit(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.wallx = game->ray.posy
			+ game->ray.perpwalldist * game->ray.raydiry;
	else
		game->ray.wallx = game->ray.posx
			+ game->ray.perpwalldist * game->ray.raydirx;
	game->ray.wallx -= floor(game->ray.wallx);
}

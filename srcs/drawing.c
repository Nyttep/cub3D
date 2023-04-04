/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:55:04 by aradice           #+#    #+#             */
/*   Updated: 2023/04/04 18:40:48 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_up(t_game *game)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
		{
			game->pos_pixel = (y * game->testimg.size_line
					+ i * (game->testimg.bpp / 8));
			game->pixel = game->testimg.addr + game->pos_pixel;
			*(unsigned int *)game->pixel = game->color_up;
			y++;
		}
		i++;
	}
}

void	ft_draw_down(t_game *game)
{
	int		i;
	int		y;

	i = 0;
	y = WIN_HEIGHT / 2;
	while (i < WIN_WIDTH)
	{
		y = WIN_HEIGHT / 2;
		while (y < WIN_HEIGHT)
		{
			game->pos_pixel = (y * game->testimg.size_line
					+ i * (game->testimg.bpp / 8));
			game->pixel = game->testimg.addr + game->pos_pixel;
			*(unsigned int *)game->pixel = game->color_down;
			y++;
		}
		i++;
	}
}

void	ft_draw_texture(t_game *game, int i)
{
	int	y;

	y = 0;
	game->ray.step = 1.0 * (double)game->texheight / game->ray.lineheight;
	game->ray.texpos = (game->ray.drawstart - WIN_HEIGHT / 2
			+ game->ray.lineheight / 2) * game->ray.step;
	y = game->ray.drawstart;
	while (y <= game->ray.drawend)
	{
		game->ray.texy = (int)game->ray.texpos & (game->texheight - 1);
		game->ray.texpos += game->ray.step;
		game->color_middle = game->texture[game->ray.texnum].addr[game->texwidth
			* game->ray.texy + game->ray.texx];
		game->pos_pixel = (y * game->testimg.size_line
				+ i * (game->testimg.bpp / 8));
		game->pixel = game->testimg.addr + game->pos_pixel;
		*(unsigned int *)game->pixel = game->color_middle;
		y++;
	}
}

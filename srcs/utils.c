/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:59:54 by aradice           #+#    #+#             */
/*   Updated: 2023/04/04 15:35:32 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_new_image(t_game *game)
{
	game->testimg.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->testimg.img)
		ft_error(game, NULL);
	game->testimg.addr = mlx_get_data_addr(game->testimg.img,
			&game->testimg.bpp, &game->testimg.size_line,
			&game->testimg.endian);
}

int	ft_close(t_game *game)
{
	ft_quit(game, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:59:54 by aradice           #+#    #+#             */
/*   Updated: 2023/04/02 18:15:55 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_new_image(t_game *game)
{
	game->testimg.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->testimg.addr = mlx_get_data_addr(game->testimg.img,
			&game->testimg.bpp, &game->testimg.size_line,
			&game->testimg.endian);
}

int	ft_close(void)
{
	exit(0);
}

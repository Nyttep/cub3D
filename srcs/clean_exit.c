/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:49:21 by paul              #+#    #+#             */
/*   Updated: 2023/04/03 18:24:41 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_quit(t_game *game, int ret)
{
	if (!game)
		exit(ret);
	if (game->fd)
		close(game->fd);
	if (game->map)
		ft_free_strs(game->map);
	free(game);
	exit(ret);
}

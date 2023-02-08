/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette_is_stupid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:25:36 by pdubois           #+#    #+#             */
/*   Updated: 2023/02/07 15:26:16 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_i_hate_norminette(t_img *set[4], t_game *game)
{
	set[0] = game->north;
	set[1] = game->south;
	set[2] = game->west;
	set[3] = game->east;
}

void	ft_norminette_made_me_do_that(char *set[6])
{
	set[0] = "NO ";
	set[1] = "SO ";
	set[2] = "WE ";
	set[3] = "EA ";
	set[4] = "F ";
	set[5] = "C ";
}

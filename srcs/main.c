/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:30 by pdubois           #+#    #+#             */
/*   Updated: 2023/02/09 17:53:47 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_game	*game;

	ft_check_basic(ac, av);
	game = malloc(sizeof(t_game));
	if (!game)
		ft_error(game, NULL);
	ft_init(game, av);
}

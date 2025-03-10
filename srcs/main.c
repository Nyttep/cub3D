/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:30 by pdubois           #+#    #+#             */
/*   Updated: 2023/04/05 15:57:43 by pdubois          ###   ########.fr       */
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
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!game->win)
		ft_error(game, NULL);
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img)
		ft_error(game, NULL);
	mlx_hook(game->win, 2, 1L << 0, ft_movements, game);
	mlx_hook(game->win, 17, 1L << 0, ft_close, game);
	mlx_loop_hook(game->mlx, ft_loop, game);
	mlx_loop(game->mlx);
	ft_quit(game, 0);
}

int	ft_loop(t_game *game)
{
	int	i;

	i = 0;
	ft_new_image(game);
	ft_draw_up(game);
	ft_draw_down(game);
	while (i < WIN_WIDTH)
	{
		ft_raypos_and_direction(game, i);
		ft_which_box_i_am(game);
		ft_lenght_ray(game);
		ft_step_init_sidedist(game);
		ft_hit_function(game);
		ft_distance_prependicular_ray(game);
		ft_heigth_line_to_draw(game);
		ft_lowest_and_highest_pixel(game);
		ft_num_texture(game);
		ft_value_wallx_when_hit(game);
		ft_coordinate_on_texture(game);
		ft_draw_texture(game, i);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->testimg.img, 0, 0);
	mlx_destroy_image(game->mlx, game->testimg.img);
	return (0);
}

int	ft_movements(int keycode, t_game *game)
{
	game->ray.movespeed = 0.1;
	game->ray.rotspeed = 0.05;
	ft_move_up(keycode, game);
	ft_move_down(keycode, game);
	ft_move_left(keycode, game);
	ft_move_right(keycode, game);
	ft_rotate_left(keycode, game);
	ft_rotate_right(keycode, game);
	if (keycode == XK_Escape)
		ft_quit(game, 0);
	return (0);
}

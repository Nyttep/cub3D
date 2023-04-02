/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:30 by pdubois           #+#    #+#             */
/*   Updated: 2023/04/02 17:46:49 by pdubois          ###   ########.fr       */
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
	tests_raycasting(game);
}


int	ft_loop(t_game *game)
{
	int		i;
	int		y;

	game->testimg.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->testimg.addr = mlx_get_data_addr(game->testimg.img, &game->testimg.bpp, &game->testimg.size_line, &game->testimg.endian);

	//haut et bas
	i = 0;
	y = 0;
	while (i < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
		{
			game->pos_pixel = (y * game->testimg.size_line + i * (game->testimg.bpp / 8));
			game->pixel = game->testimg.addr + game->pos_pixel;
			*(unsigned int *)game->pixel = game->color_up;
			y++;
		}
		i++;
	}

	i = 0;
	y = WIN_HEIGHT / 2;
	while (i < WIN_WIDTH)
	{
		y = WIN_HEIGHT / 2;
		while (y < WIN_HEIGHT)
		{
			game->pos_pixel = (y * game->testimg.size_line + i * (game->testimg.bpp / 8));
			game->pixel = game->testimg.addr + game->pos_pixel;
			*(unsigned int *)game->pixel = game->color_down;
			y++;
		}
		i++;
	}

	//rays
	i = 0;
	y = 0;
	while (i < WIN_WIDTH)
	{

		game->ray.camerax = 2 * i / (double)WIN_WIDTH - 1;
		game->ray.raydirx = game->ray.dirx + game->ray.planx * game->ray.camerax;
		game->ray.raydiry = game->ray.diry + game->ray.plany * game->ray.camerax;
		game->ray.mapx = (int)game->ray.posx;
		game->ray.mapy = (int)game->ray.posy;


		if (game->ray.raydirx != 0)
			game->ray.deltadistx = fabs(1 / game->ray.raydirx);
		else
			game->ray.deltadistx = 1e30;
		if (game->ray.raydiry != 0)
			game->ray.deltadisty = fabs(1 / game->ray.raydiry);
		else
			game->ray.deltadisty = 1e30;


		if (game->ray.raydirx < 0)
		{
			game->ray.stepx = -1;
			game->ray.sidedistx = (game->ray.posx - game->ray.mapx) * game->ray.deltadistx;
		}
		else
		{
			game->ray.stepx = 1;
			game->ray.sidedistx = (game->ray.mapx + 1.0 - game->ray.posx) * game->ray.deltadistx;
		}
		if (game->ray.raydiry < 0)
		{
			game->ray.stepy = -1;
			game->ray.sidedisty = (game->ray.posy - game->ray.mapy) * game->ray.deltadisty;
		}
		else
		{
			game->ray.stepy = 1;
			game->ray.sidedisty = (game->ray.mapy + 1.0 - game->ray.posy) * game->ray.deltadisty;
		}


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

		if (game->ray.side == 0)
			game->ray.perpwalldist = (game->ray.sidedistx - game->ray.deltadistx);
		else
			game->ray.perpwalldist = (game->ray.sidedisty - game->ray.deltadisty);


		game->ray.lineheight = (int)(WIN_HEIGHT / game->ray.perpwalldist);
		game->ray.drawstart = -game->ray.lineheight / 2 + WIN_HEIGHT / 2;
		if (game->ray.drawstart < 0)
			game->ray.drawstart = 0;
		game->ray.drawend = game->ray.lineheight / 2 + WIN_HEIGHT / 2;
		if (game->ray.drawend >= WIN_HEIGHT)
			game->ray.drawend = WIN_HEIGHT - 1;


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


		if (game->ray.side == 0)
			game->ray.wallx = game->ray.posy + game->ray.perpwalldist * game->ray.raydiry;
		else
			game->ray.wallx = game->ray.posx + game->ray.perpwalldist * game->ray.raydirx;
		game->ray.wallx -= floor(game->ray.wallx);
		game->ray.texx = (int)(game->ray.wallx * (double)game->texwidth);
		if (game->ray.side == 0 && game->ray.raydirx > 0)
			game->ray.texx = game->texwidth - game->ray.texx - 1;
		if (game->ray.side == 1 && game->ray.raydiry < 0)
			game->ray.texx = game->texwidth - game->ray.texx - 1;
		game->ray.step = (double)game->texheight / game->ray.lineheight;
		game->ray.texpos = (game->ray.drawstart - WIN_HEIGHT / 2 + game->ray.lineheight / 2) * game->ray.step;
		

		//middle
		y = game->ray.drawstart;
		while (y <= game->ray.drawend)
		{
			game->ray.texy = (int)game->ray.texpos & (game->texheight - 1);
			game->ray.texpos += game->ray.step;
			game->color_middle = game->texture[game->ray.texnum].addr[game->texwidth * game->ray.texy + game->ray.texx];
			game->pos_pixel = (y * game->testimg.size_line + i * (game->testimg.bpp / 8));
 			game->pixel = game->testimg.addr + game->pos_pixel;
 			*(unsigned int *)game->pixel = game->color_middle;
			y++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->testimg.img, 0, 0);
	mlx_destroy_image(game->mlx, game->testimg.img);
	return (0);
}

int	ft_close(void)
{
	exit(0);
}

int	ft_movements(int keycode, t_game *game)
{
	game->ray.movespeed = 0.1;
	game->ray.rotspeed = 0.05;

	if (keycode == 'w')
	{
		if (game->map[(int)(game->ray.posy)][(int)(game->ray.posx + game->ray.dirx * game->ray.movespeed)] != '1')
			game->ray.posx += game->ray.dirx * game->ray.movespeed;
		if (game->map[(int)(game->ray.posy + game->ray.diry * game->ray.movespeed)][(int)(game->ray.posx)] != '1')
			game->ray.posy += game->ray.diry * game->ray.movespeed;
	}
	else if (keycode == 's')
	{
		if (game->map[(int)(game->ray.posy)][(int)(game->ray.posx - game->ray.dirx * game->ray.movespeed)] != '1')
			game->ray.posx -= game->ray.dirx * game->ray.movespeed;
		if (game->map[(int)(game->ray.posy - game->ray.diry * game->ray.movespeed)][(int)(game->ray.posx)] != '1')
			game->ray.posy -= game->ray.diry * game->ray.movespeed;
	}
	else if (keycode == 'a')
	{
		if (game->map[(int)(game->ray.posy)][(int)(game->ray.posx - game->ray.planx * game->ray.movespeed)] != '1')
			game->ray.posx -= game->ray.planx * game->ray.movespeed;
		if (game->map[(int)(game->ray.posy + game->ray.plany * game->ray.movespeed)][(int)(game->ray.posx)] != '1')
			game->ray.posy -= game->ray.plany * game->ray.movespeed;
	}
	else if (keycode == 'd')
	{
		if (game->map[(int)(game->ray.posy)][(int)(game->ray.posx + game->ray.planx * game->ray.movespeed)] != '1')
			game->ray.posx += game->ray.planx * game->ray.movespeed;
		if (game->map[(int)(game->ray.posy - game->ray.plany * game->ray.movespeed)][(int)(game->ray.posx)] != '1')
			game->ray.posy += game->ray.plany * game->ray.movespeed;
	}
	else if (keycode == KEY_RIGHT)
	{
		//printf("%f\n", game->ray.dirx);
		game->ray.dirx = game->ray.dirx * cos(-game->ray.rotspeed) - game->ray.diry * sin(-game->ray.rotspeed);
		game->ray.diry = game->ray.dirx * sin(-game->ray.rotspeed) + game->ray.diry * cos(-game->ray.rotspeed);
		game->ray.planx = game->ray.planx * cos(-game->ray.rotspeed) - game->ray.plany * sin(-game->ray.rotspeed);
		game->ray.plany = game->ray.planx * sin(-game->ray.rotspeed) + game->ray.plany * cos(-game->ray.rotspeed);
	}
	else if (keycode == KEY_LEFT)
	{
		//printf("%f - %f - %f\n", game->ray.dirx, cos(game->ray.rotspeed), sin(game->ray.rotspeed));
		game->ray.dirx = game->ray.dirx * cos(game->ray.rotspeed) - game->ray.diry * sin(game->ray.rotspeed);
		game->ray.diry = game->ray.dirx * sin(game->ray.rotspeed) + game->ray.diry * cos(game->ray.rotspeed);
		game->ray.planx = game->ray.planx * cos(game->ray.rotspeed) - game->ray.plany * sin(game->ray.rotspeed);
		game->ray.plany = game->ray.planx * sin(game->ray.rotspeed) + game->ray.plany * cos(game->ray.rotspeed);
	}
	if (keycode == XK_Escape)
		exit(0);
	return (0);
}

void	tests_raycasting(t_game	*game)
{
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);

	game->ray.posx = (double)game->x + 0.5;
	game->ray.posy = (double)game->y + 0.5;

	mlx_hook(game->win, 2,  1L << 0, ft_movements, game);
	mlx_hook(game->win, 17, 1L << 0, ft_close, NULL);
	mlx_loop_hook(game->mlx, ft_loop, game);
	mlx_loop(game->mlx);
}
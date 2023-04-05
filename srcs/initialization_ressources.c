/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_ressources.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:34:21 by pdubois           #+#    #+#             */
/*   Updated: 2023/04/05 16:52:10 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_img(t_game *game, char *path, t_texture *img)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->width,
			&img->height);
	if (!img->img)
		return (0);
	img->addr = (int *) mlx_get_data_addr(img->img, &img->bpp, &img->size_line,
			&img->endian);
	if (!img->addr)
		return (0);
	return (1);
}

void	ft_separate_rgb(int	*color, char *rgb)
{
	int	j;

	j = 0;
	while (j < 3)
	{
		color[j++] = ft_atoi(rgb);
		while (*rgb != ',' && *rgb)
			rgb++;
		rgb++;
	}
}

int	ft_init_fc(t_game *game, char *rgb, int i)
{
	int	*color;

	if (ft_check_rgb(rgb))
		return (0);
	if (i == 4)
		color = game->floor;
	else if (i == 5)
		color = game->ceiling;
	ft_separate_rgb(color, rgb);
	if (i == 4)
	{
		game->color_down = ft_convert_rgb_to_int(game->floor);
		if (game->color_down == -1)
			return (0);
	}
	else if (i == 5)
	{
		game->color_up = ft_convert_rgb_to_int(game->ceiling);
		if (game->color_up == -1)
			return (0);
	}
	return (1);
}

void	ft_parse_and_init(t_game *game, char *set[6], char *buff, bool state[6])
{
	int	i;

	i = 0;
	while (i < 6 && buff[0] != '\n')
	{
		if (!ft_strncmp(ft_skip_spaces(buff), set[i], ft_strlen(set[i])))
		{
			if (i < 4 && !game->texture[i].img)
			{
				if (!ft_init_img(game, ft_format_path(buff), &game->texture[i]))
					ft_free_quit(game, buff);
			}
			else
				if (!ft_init_fc(game, ft_format_path(buff), i))
					ft_free_quit(game, buff);
			state[i] = 1;
			break ;
		}
		i++;
	}
	if (i == 6 && ft_is_unfinished(state))
	{
		free(buff);
		ft_error(game, "The .cub does not conform");
	}
}

char	*ft_init_ressources(t_game *game, int fd)
{
	char	*set[6];
	char	*buff;
	bool	state[6];

	ft_bzero(state, sizeof(state));
	ft_init_set(set);
	buff = get_next_line(fd);
	while (buff && ft_is_unfinished(state))
	{
		ft_parse_and_init(game, set, buff, state);
		free(buff);
		buff = get_next_line(fd);
	}
	if (ft_is_unfinished(state))
		ft_error(game, "The .cub does not conform");
	game->texwidth = game->texture[0].width;
	game->texheight = game->texture[0].height;
	return (buff);
}

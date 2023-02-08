/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_ressources.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:34:21 by pdubois           #+#    #+#             */
/*   Updated: 2023/02/08 16:35:53 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_img(t_game *game, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->width,
			&img->height);
	if (!img->img)
		ft_error(game, NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line,
			&img->endian);
	if (!img->addr)
		ft_error(game, NULL);
}

void	ft_init_fc(t_game *game, char *rgb, int i)
{
	int	*color;
	int	j;

	j = 0;
	if (ft_check_rgb(rgb))
		ft_error(game, "The floor or ceiling line does not conform");
	if (i == 4)
		color = game->floor;
	else if (i == 5)
		color = game->ceiling;
	while (j < 3)
	{
		color[j++] = ft_atoi(rgb);
		while (*rgb != ',' && *rgb)
			rgb++;
		rgb++;
	}
}

void	ft_init_walls(t_game *game, char *path, int i)
{
	t_img	*img;
	t_img	*set[4];

	ft_i_hate_norminette(set, game);
	img = set[i];
	img = malloc(sizeof(t_img));
	if (img == NULL)
		ft_error(game, NULL);
	ft_init_img(game, path, img);
}

void	ft_parse_and_init(t_game *game, char *set[6], char *buff, bool state[6])
{
	int	i;

	i = 0;
	while (i < 6 && buff[0] != '\n')
	{
		if (!ft_strncmp(ft_skip_spaces(buff), set[i], ft_strlen(set[i])))
		{
			if (i < 4)
				ft_init_walls(game, ft_format_path(buff), i);
			else
				ft_init_fc(game, ft_format_path(buff), i);
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

void	ft_init_ressources(t_game *game, int fd)
{
	char	*set[6];
	char	*buff;
	bool	state[6];

	ft_bzero(state, sizeof(state));
	ft_norminette_made_me_do_that(set);
	buff = get_next_line(fd);
	while (buff && ft_is_unfinished(state))
	{
		ft_parse_and_init(game, set, buff, state);
		free(buff);
		buff = get_next_line(fd);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:34:28 by paul              #+#    #+#             */
/*   Updated: 2023/03/31 10:46:50 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
// # include "mlx.h"
# include "libft.h"

# define BUFFER_SIZE 100

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		endian;
	int		size_line;
} t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		floor[3];
	int		ceiling[3];
	t_img	*north;
	t_img	*south;
	t_img	*west;
	t_img	*east;
}	t_game;

char	*get_next_line(int fd);
int		ft_is_newline_gnl(char *s);
int		ft_strlen_gnl(char *s);
char	*ft_kinda_strcat_gnl(char *s, char *init);
void	ft_get_reste_gnl(char *s, char *reste, int read_return);
char	*ft_cpy_and_rst_reste_gnl(char *ret, char *reste);
void	ft_init_gnl(char **s, char **ret, int *read_return, char *reste);

void	ft_quit(t_game *game);
void	ft_error(t_game *game, char *s);

void	ft_check_basic(int ac, char **av);
int		ft_check_rgb(char *str);

void	ft_init(t_game *game, char **av);
char	*ft_init_ressources(t_game *game, int fd);

char	*ft_skip_spaces(char *s);
bool	ft_is_unfinished(bool state[6]);
char	*ft_format_path(char *buff);
int		ft_is_valid_char_map(char c);

void	ft_i_hate_norminette(t_img *set[4], t_game *game);
void	ft_norminette_made_me_do_that(char *set[6]);

#endif
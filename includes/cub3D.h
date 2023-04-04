/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:34:28 by paul              #+#    #+#             */
/*   Updated: 2023/04/04 16:12:03 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define BUFFER_SIZE 	100
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define WIN_WIDTH		1920
# define WIN_HEIGHT		1080

typedef struct s_ray
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	double	raydirx;
	double	raydiry;
	double	camerax;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	movespeed;
	double	rotspeed;
	double	wallx;
	int		texnum;
	double	step;
	int		texx;
	int		texy;
	double	texpos;
}	t_ray;

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		width;
	int		height;
	int		bpp;
	int		endian;
	int		size_line;
}	t_texture;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		endian;
	int		size_line;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	int			width;
	int			height;
	t_ray		ray;
	t_img		testimg;
	int			color_up;
	int			color_down;
	int			color_middle;
	int			pos_pixel;
	char		*pixel;
	int			x;
	int			y;
	char		direction;
	t_texture	texture[4];
	int			texwidth;
	int			texheight;
	char		**map;
	int			floor[3];
	int			ceiling[3];
	int			fd;
}	t_game;

char	*get_next_line(int fd);
int		ft_is_newline_gnl(char *s);
int		ft_strlen_gnl(char *s);
char	*ft_kinda_strcat_gnl(char *s, char *init);
void	ft_get_reste_gnl(char *s, char *reste, int read_return);
char	*ft_cpy_and_rst_reste_gnl(char *ret, char *reste);
void	ft_init_gnl(char **s, char **ret, int *read_return, char *reste);

void	ft_quit(t_game *game, int ret);
void	ft_error(t_game *game, char *s);

void	ft_check_basic(int ac, char **av);
int		ft_check_rgb(char *str);
void	ft_check_map(t_game *game);
void	ft_check_after_map(t_game *game, int fd, char *buff);

void	ft_init(t_game *game, char **av);
char	*ft_init_ressources(t_game *game, int fd);
void	ft_init_map(t_game *game, int fd, char *buff);

char	*ft_skip_spaces(char *s);
bool	ft_is_unfinished(bool state[6]);
char	*ft_format_path(char *buff);
int		ft_is_valid_char_map(char c);
void	*ft_realloc_strs(void *ptr, size_t size);
int		ft_convert_rgb_to_int(int rgb[3]);
int		ft_find_max_len(int nb_line, char **strs);
void	ft_init_set(char *set[6]);
void	ft_free_quit(t_game *game, char *str);

void	tests_raycasting(t_game	*game);
int		ft_close(t_game *game);
int		ft_movements(int keycode, t_game *game);
int		ft_loop(t_game *game);

void	ft_draw_up(t_game *game);
void	ft_draw_down(t_game *game);
void	ft_draw_texture(t_game *game, int i);

void	ft_new_image(t_game *game);
void	ft_raypos_and_direction(t_game *game, int i);
void	ft_which_box_i_am(t_game *game);
void	ft_lenght_ray(t_game *game);
void	ft_step_init_sidedist(t_game *game);
void	ft_hit_function(t_game *game);
void	ft_distance_prependicular_ray(t_game *game);
void	ft_heigth_line_to_draw(t_game *game);
void	ft_lowest_and_highest_pixel(t_game *game);
void	ft_num_texture(t_game *game);
void	ft_value_wallx_when_hit(t_game *game);
void	ft_coordinate_on_texture(t_game *game);
void	ft_draw_texture(t_game *game, int i);
void	ft_player_middle_box(t_game *game);

void	ft_move_up(int keycode, t_game *game);
void	ft_move_down(int keycode, t_game *game);
void	ft_move_left(int keycode, t_game *game);
void	ft_move_right(int keycode, t_game *game);
void	ft_rotate_left(int keycode, t_game *game);
void	ft_rotate_right(int keycode, t_game *game);

#endif
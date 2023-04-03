/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:34:28 by paul              #+#    #+#             */
/*   Updated: 2023/04/03 18:18:46 by pdubois          ###   ########.fr       */
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
	double	posx; //position x du joueur
	double	posy; //position y du joueur
	double	dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double	diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double	planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double	plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double	raydirx; //calcul de direction x du rayon
	double	raydiry; //calcul de direction y du rayon
	double	camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		mapx; // coordonée x du carré dans lequel est pos
	int		mapy; // coordonnée y du carré dans lequel est pos
	double	sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double	sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double	deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double	deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int		stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit; // 1 si un mur a ete touche, 0 sinon
	int		side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double	perpwalldist; // distance du joueur au mur
	int		lineheight; //hauteur de la ligne a dessiner
	int		drawstart; //position de debut ou il faut dessiner
	int		drawend; //position de fin ou il faut dessiner
	double	movespeed;//const deplacement
	double	rotspeed; //const rotation
	double	wallx;//wallX represents the exact value where the wall was hit
	int		texnum; //numero de texture
	double	step;// How much to increase the texture coordinate per screen pixel
	int		texx;//texX is the x-coordinate of the texture, and this is calculated out of wallX.
	int		texy;//texY is the y-coordinate of the texture, and this is calculated out of wallX.
	double	texpos; // Starting texture coordinate
	
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
} t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
	t_ray	ray;
	t_img	testimg;
	int		color_up;
	int		color_down;
	int		color_middle;
	int		pos_pixel;
	char	*pixel;
	int		x;	//player x
	int		y;	//player y
	char	direction; //player direction
	t_texture	texture[4];
	int		texwidth;
	int		texheight;
	char	**map;
	int		floor[3];
	int		ceiling[3];
	int		fd;
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

void	tests_raycasting(t_game	*game);
int		ft_close(void);
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

void	ft_move_up(int keycode, t_game *game);
void	ft_move_down(int keycode, t_game *game);
void	ft_move_left(int keycode, t_game *game);
void	ft_move_right(int keycode, t_game *game);
void	ft_rotate_left(int keycode, t_game *game);
void	ft_rotate_right(int keycode, t_game *game);

#endif
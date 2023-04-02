# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 21:14:22 by pdubois           #+#    #+#              #
#    Updated: 2023/02/09 17:20:52 by pdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lXext -lX11 -lm 

NAME = cub3D
SRCS_NAME = main.c \
			get_next_line.c \
			get_next_line_utils.c \
			check.c \
			error.c \
			clean_exit.c \
			initialization.c \
			initialization_ressources.c \
			initialization_utils.c \
			norminette_is_stupid.c \
			movements.c \
			movements_rotate.c \
			drawing.c \
			raycasting_1.c \
			raycasting_2.c \
			raycasting_3.c \
			utils.c \
			check_map.c

SRCS_PATH = srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
INCS_NAME = cub3D.h
INCS_PATH = includes
INCS = $(addprefix $(INCS_PATH)/, $(INCS_NAME))
LIBS = libft/libft.a \
		minilibx-linux/libmlx_Linux.a
MLX = -lXext -lX11 -lm 
RM = rm -rf
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
			${CC} ${CFLAGS} -g -I ${INCS_PATH} -I libft -I minilibx-linux -c $< -o $@ 

${LIBS}:
			make -C libft; make -C minilibx-linux

${NAME}:	${OBJS} ${INCS} ${LIBS}
			${CC} -g -o ${NAME} ${OBJS} ${LIBS} ${MLXFLAGS}
clean:
			${RM} ${OBJS}; make -C libft fclean;

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY : all clean fclean re

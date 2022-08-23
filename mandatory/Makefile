# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izail <izail@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 06:10:23 by mhaddaou          #+#    #+#              #
#    Updated: 2022/08/23 13:01:55 by izail            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/parsing/check_extension.c src/parsing/cub3d.c src/parsing/ft_free.c src/parsing/ft_str.c src/get_next_line/gnl.c src/parsing/read_map.c src/parsing/util.c src/parsing/ft_check.c src/rayCasting/initializeWindow.c
OBJ = ${SRC:.c=.o}

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = cub3D
RM = rm -rf

all: ${NAME}
${NAME} : ${OBJ}
		${CC} ${FLAGS} ${MLX} -o ${NAME} ${OBJ}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re : fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 06:10:23 by mhaddaou          #+#    #+#              #
#    Updated: 2022/08/22 06:15:35 by mhaddaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/check_extension.c src/cub3d.c src/ft_free.c src/ft_strerror.c src/ft_strjoin.c src/gnl.c src/read_map.c src/util.c
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
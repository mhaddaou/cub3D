# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izail <izail@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 00:39:35 by mhaddaou          #+#    #+#              #
#    Updated: 2022/09/16 18:53:04 by izail            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
BONUS = cub3D_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror

MLX =  -lmlx -framework OpenGL -framework AppKit

SRC_M = src/calculdistance.c  src/CheckMap.c  src/check_extention.c src/CheckMapTwo.c src/CheckTrueMap.c src/CheckTrueMap2.c src/CheckTrueMap3.c src/GetElementC.c src/GetElementF.c \
		src/GetTrueMap.c src/cub3d.c src/draw_texture.c src/err_hand.c src/ft_free.c src/ft_init.c src/ft_mlx.c src/initMap.c src/movement.c src/position_player.c \
		src/print.c src/print2.c src/raycasting.c src/raycasting2.c src/raycasting3.c src/raycasting4.c src/read_map.c src/rotate.c src/texture.c src/utils.c \

# SRC_B = bonus/*.c

SRC_L = includes/libft/ft_memset.c includes/libft/ft_bzero.c includes/libft/ft_memcpy.c includes/libft/ft_memmove.c includes/libft/ft_memchr.c includes/libft/ft_strlcpy.c includes/libft/ft_strlcat.c includes/libft/ft_strchr.c \
		includes/libft/ft_strrchr.c includes/libft/ft_strnstr.c  includes/libft/ft_strlen.c  includes/libft/ft_strncmp.c includes/libft/ft_atoi.c includes/libft/ft_isalpha.c includes/libft/ft_isdigit.c includes/libft/ft_isalnum.c includes/libft/ft_isascii.c includes/libft/ft_isprint.c \
		includes/libft/ft_toupper.c includes/libft/ft_tolower.c includes/libft/ft_calloc.c includes/libft/ft_strdup.c includes/libft/ft_strjoin.c  includes/libft/ft_substr.c  includes/libft/ft_strtrim.c includes/libft/ft_split.c \
		includes/libft/ft_itoa.c  includes/libft/ft_striteri.c includes/libft/ft_putchar_fd.c includes/libft/ft_putstr_fd.c includes/libft/ft_putendl_fd.c includes/libft/ft_putnbr_fd.c includes/libft/ft_memcmp.c \

SRC_GNL = includes/gnl/get_next_line.c \

HEADERS = includes/cub3d.h \
			includes/libft/libft.h \
			includes/gnl/get_next_line.h \

OBJ_M	= $(SRC_M:.c=.o)
# OBJ_B	= $(SRC_B:.c=.o)

OBJ_GNL	= $(SRC_GNL:.c=.o)
OBJ_L	= $(SRC_L:.c=.o)

all: $(NAME)

$(NAME):  $(OBJ_L) $(OBJ_GNL) $(OBJ_M) $(HEADERS)
	$(CC) $(FLAGS)  $(OBJ_L) $(OBJ_GNL) $(OBJ_M) -I /usr/local/include  -o $(NAME) -L /usr/local/lib $(MLX)

# bonus : $(BONUS)

# $(BONUS): $(OBJ_B) $(OBJ_GNL) $(OBJ_PRINTF) 
# 	$(CC) $(FLAGS) $(MLX) $(OBJ_B) $(OBJ_GNL) $(OBJ_PRINTF) -o $(BONUS)

clean:
	@rm -rf $(OBJ_M) $(OBJ_GNL) $(OBJ_L)
	@rm -rf $(OBJ_B) $(OBJ_GNL) $(OBJ_L)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all





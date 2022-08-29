# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 00:39:35 by mhaddaou          #+#    #+#              #
#    Updated: 2022/08/27 13:50:06 by mhaddaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: fclean
	@cd library && make all
	@gcc   -I /usr/local/include src/*.c library/library.a -o cub3D -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit

clean:
	@cd library && make clean
	@rm -f cub3D

fclean: clean
	@cd library && make fclean


re:all


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izail <izail@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 00:39:35 by mhaddaou          #+#    #+#              #
#    Updated: 2022/09/14 18:57:12 by izail            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAMEB = cub3D_bonus
FLAG = -W -W -W

all:
	@cd library && make all
	@gcc  ${FLAG} -I /usr/local/include src/*.c library/library.a -o ${NAME} -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit

clean:
	@cd library && make clean
	@rm -f ${NAME}
	@rm -f ${NAMEB}

fclean: clean
	@cd library && make fclean
	
bonus:fclean
	@cd library && make all
	@gcc  ${FLAG} -I /usr/local/include bonus/*.c library/library.a -o ${NAMEB} -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit




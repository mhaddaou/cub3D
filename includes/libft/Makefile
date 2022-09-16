# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izail <izail@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 18:35:00 by izail             #+#    #+#              #
#    Updated: 2022/09/16 17:46:59 by izail            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

MANDATORY = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c  ft_substr.c  ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memcmp.c \

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		

OBJS 	= $(MANDATORY:.c=.o)
OBJS_B 	= $(BONUS:.c=.o)

%.o : %.c 
		$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS) $(HEADER)
	$(AR) $(NAME) $(OBJS) 

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

bonus: $(OBJS_B) $(OBJS) $(HEADER)
	$(AR) $(NAME) $(OBJS_B) $(OBJS)

re: fclean all

.PHONY: bonus all clean fclean re

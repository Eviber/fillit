# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 19:09:01 by ygaude            #+#    #+#              #
#    Updated: 2017/01/05 17:10:42 by ygaude           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/ft_fillit.c \
		srcs/check_file.c \
		srcs/read_tetriminos_file.c \
		srcs/get_pieces.c \
		srcs/transform_pieces.c \
		srcs/transform_grid.c \
		srcs/solve_fillit.c \
		srcs/error.c
LIB = libft/
FLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:c=o}

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME): lib $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIB)libft.a -I $(LIB) -o $(NAME)
	@echo Done !

lib:
	make -C $(LIB)

clean:
	rm -f $(OBJS)
	make -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB) fclean

re: fclean all

.PHONY: clean fclean re all lib

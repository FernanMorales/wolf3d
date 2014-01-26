# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmorales <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/12 18:18:25 by fmorales          #+#    #+#              #
#    Updated: 2014/01/19 21:13:40 by fmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS		=	-Wextra -Wall -Werror -g3
INCLUDE		=	-L/usr/X11/lib -lmlx -lXext -lX11 -lm -I.
SRC		=	main.c			\
			background.c	\
			compute_walls.c	\
			pixel_put.c
NAME		=	wolf3d
RM		=	rm -f
OBJ		=	$(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

me: all clean

.PHONY: all clean fclean re

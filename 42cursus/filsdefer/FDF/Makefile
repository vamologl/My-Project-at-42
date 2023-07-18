# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 07:50:06 by vamologl          #+#    #+#              #
#    Updated: 2023/07/18 10:34:06 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRC = testwindow.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC)  -I/home/vamologl/Desktop/42cursus/FdF/FDF/minilibx-linux -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L/home/vamologl/Desktop/42cursus/FdF/FDF/minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

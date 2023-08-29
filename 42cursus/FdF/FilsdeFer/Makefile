# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 08:40:07 by vamologl          #+#    #+#              #
#    Updated: 2023/08/29 08:40:11 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f
INCLUDE = include

SRCS = testwindow.c

OBJS = $(SRCS:.c=.o)

$%.o: $%.c
	$(CC) $(CFLAGS) $(SRCS) mlx/libmlx_Linux.a -lXext -lX11 -lm -lz -c $< -o $@

$(NAME): ${OBJS}
	$(CC) $(OBJS) mlx/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME)
	
all: ${NAME}

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)

re: fclean all

.PHONY: re clean fclean all

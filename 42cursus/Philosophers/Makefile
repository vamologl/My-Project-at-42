# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 11:34:54 by vamologl          #+#    #+#              #
#    Updated: 2023/12/18 11:34:55 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -pthread
NAME = Philosopher
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = main.c \
	error.c \
	utils/atoi.c \
	utils/time.c \
	utils/debug.c \

OBJS = $(SRCS:.c=.o)


all : $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(CC)  $(OBJS) -o $(NAME)

.PHONY : all clean fclean re

#.silent

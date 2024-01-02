# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 09:57:21 by vamologl          #+#    #+#              #
#    Updated: 2024/01/02 09:57:23 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -pthread
NAME = philo
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = main.c \
	error.c \
	initial.c \
	state.c \
	threads.c \
	utils.c \

OBJS = $(SRCS:.c=.o)


all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(CC)  $(OBJS) -o $(NAME)

.PHONY : all clean fclean re

#.silent


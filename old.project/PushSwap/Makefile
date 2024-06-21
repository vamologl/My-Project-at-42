# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 14:24:08 by vamologl          #+#    #+#              #
#    Updated: 2023/12/04 14:34:26 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g3

FTPF = include/ft_printf/ft_itoa.c \
	include/ft_printf/ft_print_hex.c \
	include/ft_printf/ft_print_ptr.c \
	include/ft_printf/ft_print_unsigned.c \
	include/ft_printf/ft_printf_function.c \
	include/ft_printf/ft_printf.c \

SRCS = main.c \
	algo/Bigalgo_utils.c \
	algo/bigalgo.c \
	algo/mini_sort.c \
	command/Fonction.c \
	command/Move_A.c \
	command/Move_B.c \
	command/Move_AnB.c \
	error.c \
	function_utils.c \
	stack_control.c \
	stack_utils.c \

OBJS = $(SRCS:.c=.o) $(FTPF:.c=.o)


all : $(NAME)

%.o : %.c
	$(CC)  -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(CC)  $(OBJS) -o $(NAME)

.PHONY : all clean fclean re

#.silent
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
CFLAGS = -Wall -Werror -Wextra
CFSAFLAGS = -fsanitize=address
CGFLAGS = -g3
RM = rm -f

MLX = mlx/libmlx_Linux.a -lXext -lX11 -lm -lz

MINILIB = minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz

SRCST =	test_window.c \


SRCS = 	src/main.c \
		draw/draw.c \
		draw/render.c \
		utils/utils0.c \
		utils/utils1.c \
		utils/utils2.c \
		utils/utils3.c \
		map/read_file.c \
		include/ft_printf/ft_itoa.c \
		include/ft_printf/ft_printf.c \
		include/ft_printf/ft_print_hex.c \
		include/ft_printf/ft_print_ptr.c \
		include/ft_printf/ft_print_unsigned.c \
		include/ft_printf/ft_printf_function.c \

OBJS = $(SRCS:.c=.o)

$%.o: $%.c
	$(CC) $(CFLAGS) $(SRCS) $(MINILIB) -c $< -o $@

$(NAME): ${OBJS}
	$(CC) $(OBJS) $(CGFLAGS) $(MINILIB) -o $(NAME)
	
all: ${NAME}

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)

re: fclean all

.PHONY: re clean fclean all

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
INCLUDE = include

SRCS = 	main.c \
		draw/draw.c \
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
	$(CC) $(CFLAGS) $(SRCS) mlx/libmlx_Linux.a -lXext -lX11 -lm -lz -c $< -o $@

$(NAME): ${OBJS}
	$(CC) $(OBJS) $(CGFLAGS) mlx/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME)
	
all: ${NAME}

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)

re: fclean all

.PHONY: re clean fclean all

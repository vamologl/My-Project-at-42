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
NAMEBNS = FdF_bonus

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
CFSAFLAGS = -fsanitize=address
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
		map/check_map.c \
		include/ft_printf/ft_itoa.c \
		include/ft_printf/ft_printf.c \
		include/ft_printf/ft_print_hex.c \
		include/ft_printf/ft_print_ptr.c \
		include/ft_printf/ft_print_unsigned.c \
		include/ft_printf/ft_printf_function.c \

SRCSB =	src/main_bonus.c \
		draw/draw_bonus.c \
		draw/render_bonus.c \
		utils/utils0_bonus.c \
		utils/utils1_bonus.c \
		utils/utils2_bonus.c \
		utils/utils3_bonus.c \
		map/read_file_bonus.c \
		map/check_map_bonus.c \
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
	$(CC) $(OBJS) $(MINILIB) -o $(NAME)


	
all: ${NAME}

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSBNS)

fclean:
	$(RM) $(NAME)
	$(RM) $(NAMEBNS)
	$(RM) $(OBJS)
	$(RM) $(OBJSBNS)

re: fclean all

#bonus 
OBJSBNS = $(SRCSB:.c=.o)

$%_bonus.o: $%_bonus.c
	$(CC) $(CFLAGS) $(SRCSB) $(MINILIB) -c $< -o $@

$(NAMEBNS): ${OBJSBNS}
	$(CC) $(OBJSBNS) $(MINILIB) -o $(NAMEBNS)

bonus:	$(NAMEBNS)

rebonus : fclean bonus
#mem debug

exe :
	make re && valgrind --leak-check=full --show-leak-kinds=all ./FdF ../tmp/maps/test_maps/42.fdf

debugmem: re exe

.PHONY: re clean fclean all bonus rebonus
# .SILENT:

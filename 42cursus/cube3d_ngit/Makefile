# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 11:11:30 by vamologl          #+#    #+#              #
#    Updated: 2024/06/27 13:57:32 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = Cube3d
CFLAGS = -Wall -Wextra -Werror -g3

FLAGLFT = -Llibft -lft
FLAGGC = -Llibgc -lft
MINILIB = minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz

SRCS = raycaster/raycast.c \
	player/player.c \
	get_next_line.c \
	utils_tab.c \
	makemap.c \
	main.c \
	check/checkmap.c \
	raycaster/color.c \
	gc/gc_split.c \
	gc/gc_utils.c \
	gc/gc.c \
	gc/itoa_gc.c \
	gc/ll.c \


OBJS = $(SRCS:.c=.o)

all : $(NAME)

alldb : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(FLAGLFT) $(MINILIB) -c $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C libft
	@echo "clean"

clear :
	rm -f $(OBJS)
	$(MAKE) clean -C libft
	@echo "clear"

#------------------------------------#

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

	@echo "fclean"


fclear : clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

	@echo "fclear"

#------------------------------------#

re : fclean all

$(NAME) : $(OBJS)
	@make -C libft
	$(CC)  $(OBJS) -o $(NAME) -Iinclude $(FLAGLFT) $(MINILIB) -g3
	@echo "Re"

.PHONY : all clean fclean re

.SILENT:

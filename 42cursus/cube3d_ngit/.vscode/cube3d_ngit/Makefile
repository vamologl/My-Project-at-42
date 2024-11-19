# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 11:11:30 by vamologl          #+#    #+#              #
#    Updated: 2024/09/16 13:49:05 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = Cube3d
CFLAGS = -Wall -Wextra -Werror -g3

FLAGLFT = -Llibft -lft
FLAGGC = -Llibgc -lft
MINILIB = minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz

SRCS = raycaster/raycast.c \
	raycaster/raycast2.c \
	raycaster/color.c \
	raycaster/color_convert.c \
	raycaster/render.c \
	raycaster/animation.c \
	raycaster/draw.c \
	raycaster/get_tex_color.c \
	player/player.c \
	player/player_rotation.c \
	player/player_movement.c \
	player/player_movement_doors.c \
	check/check_player_pos.c \
	check/check_texture.c \
	check/checkmap_symbols.c \
	check/checkmap.c \
	check/check_size_texture.c \
	raycaster/raycast_texture.c \
	get_next_line.c \
	utils_tab.c \
	makemap.c \
	main.c \
	gc/ll.c \
	texture_loading.c \
	gc/gc_split.c \
	gc/gc_utils.c \
	gc/gc.c \
	gc/itoa_gc.c \
	free.c \
	player/door_gest.c \

SRCS2 = test.c


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

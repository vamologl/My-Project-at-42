# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 11:11:30 by vamologl          #+#    #+#              #
#    Updated: 2024/06/21 13:44:57 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = Cube3d
CFLAGS = -Wall -Wextra -Werror -g3

FLAGLFT = -Llibft -lft
FLAGGC = -Llibgc -lft
MINILIB = minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz

SRCS = raycaster/raycast.c \
	get_next_line.c \
	main.c \
	makemap.c \
	utils_tab.c \

OBJS = $(SRCS:.c=.o)


all : $(NAME)

alldb : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(FLAGLFT) $(MINILIB) -c $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C libft
	$(MAKE) clean -C gc
	@echo "clean"

clear :
	rm -f $(OBJS)
	$(MAKE) clean -C libft
	$(MAKE) clean -C gc
	@echo "clear"

#------------------------------------#

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C gc

	@echo "fclean"


fclear : clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C gc

	@echo "fclear"

#------------------------------------#

re : fclean all

$(NAME) : $(OBJS)
	@make -C libft
	@make -C gc
	$(CC)  $(OBJS) -o $(NAME) -Iinclude $(FLAGLFT) $(FLAGGC) $(MINILIB) gc/libgc.a -g3
#	$(CC)  $(OBJS) -o $(NAME) -Iinclude $(FLAGLFT) $(FLAGGC) gc/libgc.a -lreadline -g3
	@echo "Re"

.PHONY : all clean fclean re

.SILENT:

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 09:39:36 by vamologl          #+#    #+#              #
#    Updated: 2023/08/28 09:39:39 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g3
CC = gcc
RM = rm -f

NAME_SERVER = server
NAME_CLIENT = client

STORAGE = storage/minitalk.c storage/minitalk1.c
FT_PRINTF = storage/ft_printf/libftprintf.a

SRC_SERVER = server.c
SRC_CLIENT = client.c



all: $(NAME_CLIENT)  $(NAME_SERVER)

$(NAME_SERVER) : 
	$(CC) $(CFLAGS) $(SRC_SERVER) $(STORAGE) $(FT_PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT) : 
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(STORAGE) $(FT_PRINTF) -o $(NAME_CLIENT)

clean:
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fcleab re

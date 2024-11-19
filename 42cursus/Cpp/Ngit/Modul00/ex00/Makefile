# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 11:11:30 by vamologl          #+#    #+#              #
#    Updated: 2024/09/24 10:23:07 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

NAME = megaphone

FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = megaphone.cpp \

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
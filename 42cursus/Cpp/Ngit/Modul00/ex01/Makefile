# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 10:29:59 by vamologl          #+#    #+#              #
#    Updated: 2024/09/24 11:22:52 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

NAME = PhoneBook

FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	Contact.cpp \
	Phonebook.cpp \

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
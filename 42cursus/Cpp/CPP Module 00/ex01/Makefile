# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 10:29:59 by vamologl          #+#    #+#              #
#    Updated: 2024/10/28 10:41:41 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++

NAME = PhoneBook

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	Contact.cpp \
	PhoneBook.cpp \

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME) 

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME) $(OBJS)

re : fclean all

.PHONY: all clean fclean re
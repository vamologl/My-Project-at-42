# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 11:11:30 by vamologl          #+#    #+#              #
#    Updated: 2024/10/28 10:41:15 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++

NAME = megaphone

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

SRCS = megaphone.cpp \

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
CPP = c++

NAME = Zombie

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	newZombie.cpp \
	randomChump.cpp \
	Zombie.cpp \

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

all : $(STORE) $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME) $(OBJS)

re : fclean all

.PHONY: all clean fclean re
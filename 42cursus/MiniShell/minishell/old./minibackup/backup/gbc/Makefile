
SRCS =	gc.c	\
		ll.c

CC = cc
RM = rm -f
OBJS = ${SRCS:.c=.o}
NAME = libgc.a
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
DEBUG =

%.o : %.c
	$(CC) $(FLAGS) $(INCLUDE) $(DEBUG) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

test : $(NAME)
	$(CC) $(FLAGS) $(INCLUDE) test.c -c -o test.o
	$(CC) $(FLAGS) test.o -L. -lgc $(INCLUDE) -o test

clean :
	$(RM) $(OBJS)
	$(RM) test.o

fclean : clean
	$(RM) $(NAME)
	$(RM) test

re : fclean all

.PHONY: all clean fclean re

.SILENT:
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 11:11:30 by vamologl          #+#    #+#              #
#    Updated: 2024/04/18 10:13:55 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = minishell
CFLAGS = -Wall -Wextra -Werror -g3

FLAGLFT = -Llibft -lft
FLAGGC = -Llibgc -lft

SRCS = main.c \
	builtin/exit/exit.c \
	builtin/exit/exit_utils.c \
	builtin/export/ft_export.c \
	builtin/export/export_utils.c \
	builtin/export/export_utils2.c \
	builtin/ft_pwd.c \
	builtin/ft_cd.c \
	builtin/echo/ft_echo.c \
	builtin/echo/ft_echo_utils.c \
	builtin/ft_unset.c \
	builtin/ft_env.c \
	exec/exec.c \
	exec/exec2.c\
	exec/exec_utils.c\
	parse/command.c\
	parse/ft_super_split.c \
	parse/ft_super_split2.c \
	parse/parser.c \
	parse/parse_env_var.c \
	parse/parser_utils.c \
	parse/parser_utils2.c \
	parse/parser_utils3.c \
	parse/parser_utils4.c\
	parse/parser_utils5.c\
	parse/token.c \
	parse/token2.c \
	redir_pipe/gest_redir.c \
	redir_pipe/gest_pipeline.c\
	redir_pipe/gest_redir_utils.c \
	redir_pipe/gest_redir_utils1.c \
	redir_pipe/gest_redir_utils2.c \
	redir_pipe/gest_redir_utils3.c \
	Utils/utils.c \
	Utils/utils2.c \
	Utils/itoa_gc.c \
	Utils/gc_utils.c \
	Utils/gc_split.c \
	user.c \
	gest_struct.c \
	parse/init_input_parser.c \
	parse/init_input_parser2.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

alldb : $(NAME)

leaks : $(NAME)
	@make clean
	valgrind --suppressions=./.valgrind_ignore_leaks.txt --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --show-mismatched-frees=yes --read-var-info=yes ./minishell

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C libft
	$(MAKE) clean -C gbc
	@echo "clean"

clear :
	rm -f $(OBJS)
	$(MAKE) clear -C libft
	$(MAKE) clean -C gbc
	@echo "clear"

#------------------------------------#

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C gbc

	@echo "fclean"


fclear : clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C gbc

	@echo "fclear"

#------------------------------------#

re : fclean all

$(NAME) : $(OBJS)
	@make -C libft
	@make -C gbc
	$(CC)  $(OBJS) -o $(NAME) -Iinclude $(FLAGLFT) $(FLAGGC) gbc/libgc.a -lreadline -g3
	@echo "Re"

.PHONY : all clean fclean re

.SILENT:

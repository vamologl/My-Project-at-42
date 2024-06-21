# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 11:11:30 by vamologl          #+#    #+#              #
#    Updated: 2024/06/11 15:26:09 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = minishell
CFLAGS = -Wall -Wextra -Werror -g3

FLAGLFT = -Llibft -lft
FLAGGC = -Llibgc -lft

SRCS = main.c \
	builtin/command.c \
	builtin/echo/ft_echo.c \
	builtin/echo/ft_echo_write.c \
	builtin/exit/exit.c \
	builtin/exit/exit_alter.c \
	builtin/exit/exit_utils.c \
	builtin/export/export_env.c \
	builtin/export/export_sort.c \
	builtin/export/ft_export.c \
	builtin/ft_cd.c \
	builtin/ft_env.c \
	builtin/ft_pwd.c \
	builtin/ft_unset.c \
	check/check_char.c \
	check/check_char2.c \
	check/check_more_redir.c \
	check/check_redir.c \
	check/check_string_exist.c \
	check/check_parser.c \
	exec/exec.c \
	exec/exec_build.c \
	gc/gc_split.c \
	gc/gc_utils.c \
	gc/itoa_gc.c \
	gest/gest_char_token.c \
	gest/gest_pipeline.c \
	gest/gest_struct.c \
	gest/gest_tab_command.c \
	gest/gest_token.c \
	gest/get_next_line.c \
	gest/parser.c \
	gest/replace_dollar_token.c \
	gest/string_gest.c \
	gest/utils.c \
	redirection/correct_input_parser.c \
	redirection/correct_input_parser2.c \
	redirection/here_doc.c \
	redirection/init_input.c \
	redirection/init_output.c \
	signal.c \
	super_split/ft_super_split.c \
	super_split/ft_super_split_utils.c \
	user/user.c \
	user/user_path.c \

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
	$(CC)  $(OBJS) -o $(NAME) -Iinclude $(FLAGLFT) $(FLAGGC) gc/libgc.a -lreadline -g3
	@echo "Re"

.PHONY : all clean fclean fclear clear re

#.SILENT:

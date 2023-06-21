# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamologl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 10:18:47 by vamologl          #+#    #+#              #
#    Updated: 2023/06/19 10:55:16 by vamologl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fdf

SRC		=					\

SRCDIR	:=	src
OBJDIR	:=	obj
DEPDIR	:=	dep
INCDIR	:=	inc
LIBDIR	:=	lib

TMP		:=	.tmp.txt

SRCLOCA	:=	$(shell find $(SRCDIR) -type d)
OBJLOCA	:=	$(subst $(SRCDIR), $(OBJDIR), $(SRCLOCA))
DEPLOCA	:=	$(subst $(SRCDIR), $(DEPDIR), $(SRCLOCA))

OBJ		:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEP		:=	$(addprefix $(DEPDIR)/, $(SRC:.c=.d))
SRC		:=	$(addprefix $(SRCDIR)/, $(SRC))

LIBFT_PATH	:= $(LIBDIR)/libft
include $(LIBFT_PATH)/include.mk

LIBPF_PATH	:= $(LIBDIR)/ft_printf
include $(LIBPF_PATH)/include.mk

LIB_LINK	+=	-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
LIB_INC		+=	-I /usr/local/include

LIB_LINK	+=	-lm

CC		?=	cc

INCFLAG	:= -I $(INCDIR) $(LIB_INC)
STDFLAG	?=	-std=c11
WFLAGS	?=	-Wall -Wextra -Werror
CFLAGS	=	$(WFLAGS) $(INCFLAG) $(STDFLAG)

DEPGEN	:=	$(CC)
DEPFLAG	:=	-MM $(INCFLAG)

LD		:=	$(CC)
LDFLAG	:=	$(LIB_LINK)

CLANG_INSTALLED	:= $(shell which clang > /dev/null 2> /dev/null && echo yes)

ifdef TERM
RED			:=	"\033[1;31m"
GREEN		:=	"\033[0;32m"
BGREEN		:=	"\033[1;32m"
BLUE		:=	"\033[0;34m"
YELLOW		:=	"\033[0;33m"
PURPLE		:=	"\033[0;35m"
CYAN		:=	"\033[0;36m"
GREY		:=	"\033[0;37m"

COLRESET	:=	"\033[0m"
endif

COMPCOLOR	:=	$(GREEN)
LINKCOLOR	:=	$(PURPLE)
ONGOINGCOL	:=	$(YELLOW)
KOCOLOR		:=	$(RED)
RMCOLOR		:=	$(GREY)

MOVELINE	:=	"\033[1A"
CLEARLINE	:=	"\033[K"

all:		$(NAME)

$(NAME):	$(OBJ) | $(LIBPF_PATH)/$(LIBPF) $(LIBFT_PATH)/$(LIBFT)
	@ echo $(ONGOINGCOL)[...]$(COLRESET)"	: "$@$(MOVELINE)
	@ $(LD) -o $(NAME) $(OBJ) $(LDFLAG) &> $(TMP) && \
		(echo $(CLEARLINE)$(LINKCOLOR)[$(NAME)]$(COLRESET)"	: created"  ; \
			cat $(TMP) | sed -e "s/^/    /g" ; rm $(TMP)) || \
		(echo $(CLEARLINE)$(KOCOLOR)[KO]$(COLRESET)"	: linkage fail" ; \
			cat $(TMP) | sed -e "s/^/    /g" ; rm $(TMP) ; exit 1)

$(OBJDIR)/%.o:		$(SRCDIR)/%.c | $(OBJDIR) $(DEPDIR)
	@ echo $(ONGOINGCOL)[...]$(COLRESET)"	: "$@$(MOVELINE)
	@ $(CC) -c $< $(CFLAGS) -o  $@ &> $(TMP) && \
		(echo $(CLEARLINE)$(COMPCOLOR)[OK]$(COLRESET)"	: "$@ ; \
			cat $(TMP) | sed -e "s/^/    /g") || \
		(echo $(CLEARLINE)$(KOCOLOR)[KO]$(COLRESET)"	: "$@ ; \
			cat $(TMP) | sed -e "s/^/    /g" ; rm $(TMP) ; exit 1)
	@ $(DEPGEN) -c $< $(DEPFLAG) -MQ $@ \
		> $(subst $(SRCDIR), $(DEPDIR), $(<:.c=.d))

$(LIBFT_PATH)/$(LIBFT):
	@ echo $(ONGOINGCOL)[...]$(COLRESET)"	: "$@$(MOVELINE)
	@ $(MAKE) -C $(LIBFT_PATH) --no-print-directory > $(TMP) 2> $(TMP) && \
		(echo $(CLEARLINE)$(CYAN)[OK]$(COLRESET)"	: "$@ ; rm $(TMP)) || \
		(echo $(CLEARLINE)$(KOCOLOR)[KO]$(COLRESET)"	: "$@ ; \
			cat $(TMP) | sed -e "s/^/    /g" ; rm $(TMP) ; exit 1)

$(LIBPF_PATH)/$(LIBPF):
	@ echo $(ONGOINGCOL)[...]$(COLRESET)"	: "$@$(MOVELINE)
	@ $(MAKE) -C $(LIBPF_PATH) --no-print-directory > $(TMP) 2> $(TMP) && \
		(echo $(CLEARLINE)$(CYAN)[OK]$(COLRESET)"	: "$@ ; rm $(TMP)) || \
		(echo $(CLEARLINE)$(KOCOLOR)[KO]$(COLRESET)"	: "$@ ; \
			cat $(TMP) | sed -e "s/^/    /g" ; rm $(TMP) ; exit 1)

$(OBJDIR):
	@ mkdir -p $(OBJLOCA)
$(DEPDIR):
	@ mkdir -p $(DEPLOCA)

warn:	WFLAGS := -Wall -Wextra -ansi -Wpedantic -Wno-vla

ifdef CLANG_INSTALLED
warn:	CC := clang
warn:	WFLAGS += -Weverything
endif
warn:	lre

ffcheck:	$(NAME)
	@ nm -u $(NAME) | \
		sed -e 's/^\s*U\s//g' | grep -Ev '^\s*w\s|^__|dyld_stub_binder' | \
		grep -Ev \
			`cat .function_whitelist.txt | \
			sed -e 's/^/\^_?/g' | sed -e 's/$$/|/g' | \
			tr -d '\n' | sed 's/|$$//g'` &> $(TMP) ; \
		wc -l < $(TMP) | grep -e '^\s*\0$$' &> /dev/null && \
	echo $(BGREEN)[func]$(COLRESET)"	: no forbiden functions found" || \
	(echo $(RED)[func]$(COLRESET)"	: forbiden functions found" ; \
		cat $(TMP) | sed -e "s/^/    /g" ; rm $(TMP))

norm:
	@ norminette $(SRC) $(INCDIR) | \
		(! grep -E -B 1 "(^Warning|^Error)" &> $(TMP)) && \
		echo $(CYAN)[NORM]$(COLRESET)"	: pass, it's ok for now" || \
		(echo $(RED)[NORM]$(COLRESET)"	: you failed miserably !" ; \
		cat $(TMP) | sed -e "s/^/    /g" ; rm $(TMP))

sure: warn ffcheck norm

debug:	WFLAGS := -g -ggdb
debug:	all

rdebug:	WFLAGS := -g -ggdb
rdebug:	lre

test:	WFLAGS :=
test:	all

rtest:	WFLAGS :=
rtest:	lre

lclean:
	@ rm -r $(OBJDIR) &> /dev/null && \
		echo $(RMCOLOR)[CLR]$(COLRESET)"	:" obj ; (exit 0)
	@ rm -r $(DEPDIR) &> /dev/null && \
		echo $(RMCOLOR)[CLR]$(COLRESET)"	:" dep ; (exit 0)

lfclean: lclean
	@ rm $(NAME) &> /dev/null && \
		echo $(RMCOLOR)[CLR]$(COLRESET)"	:" $(NAME) ; (exit 0)

lre: lfclean all

clean: lclean
	@ rm -f $(TMP)
	@ $(MAKE) -C $(LIBFT_PATH) --no-print-directory clean
	@ $(MAKE) -C $(LIBPF_PATH) --no-print-directory clean &> /dev/null
	@ echo $(RMCOLOR)[CLR]$(COLRESET)"	:" ft_printf obj

fclean:	lfclean
	@ $(MAKE) -C $(LIBFT_PATH) --no-print-directory fclean
	@ $(MAKE) -C $(LIBPF_PATH) --no-print-directory fclean &> /dev/null
	@ echo $(RMCOLOR)[CLR]$(COLRESET)"	:" ft_printf obj
	@ echo $(RMCOLOR)[CLR]$(COLRESET)"	:" libprintf.a

re:		fclean all

.PHONY: all clean fclean re
.PHONY: callg ffcheck norm sure
.PHONY: debug warn test rtest
.PHONY: lclean lfclean lre

-include $(DEP)


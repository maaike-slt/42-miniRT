# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msloot <msloot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 19:19:04 by msloot            #+#    #+#              #
#    Updated: 2025/05/24 15:07:42 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	miniRT
CC = 	cc
AR =	ar rcs
RM = 	rm -rf

CFLAGS =	-Wall -Werror -Wextra
CFLAGS +=	-g
# CFLAGS +=	-fsanitize=address

UNAME = $(shell uname)

LDFLAGS	=	-lXext -lX11 -lm
# LDFLAGS		=	-Lmlx -lmlx -L/usr/lib $(MLXINC) -lXext -lX11 -lm -lz

# **************************************************************************** #
#	MAKEFILE	#

MAKEFLAGS += --silent

SHELL := bash

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	 LIB	#

LIBPATH =	./libft/
LIBNAME =	$(LIBPATH)libft.a
LIBINC =	-I$(LIBPATH)

MLXPATH =	./mlx/
MLXNAME =	$(MLXPATH)libmlx.a
MLXINC =	-I$(MLXPATH)

# **************************************************************************** #
#	SOURCE	#

SRC_PATH =	./src/
OBJ_PATH =	./obj/
INC =		./inc/

SRC_NAME =	main.c \
			init.c \
			parse/parse.c parse/camera.c \
			parse/puterr.c \
			close_win.c create_window.c hook.c handle_keycode.c \
			render.c \
			free.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

# SRC =		$(wildcard $(SRC_PATH)*.c) $(wildcard $(SRC_PATH)**/*.c)
# SRC_NAME =	$(subst $(SRC_PATH), , $(SRC))

OBJ_NAME =	$(SRC_NAME:.c=.o)
OBJ =		$(addprefix $(OBJ_PATH), $(OBJ_NAME))

# *************************************************************************** #

define	progress_bar
	i=0
	while [[ $$i -le $(words $(SRC)) ]] ; do \
		printf " " ; \
		((i = i + 1)) ; \
	done
	printf "$(B)]\r[$(GRE)"
endef

# *************************************************************************** #
#	RULES	#

ifeq ($(UNAME), Linux)
all:		launch $(NAME)
	@printf "\n$(B)$(MAG)$(NAME) compiled$(D)\n"
else
all:
	@echo "$(B)$(RED)Error: Only Linux supported.$(D)"
endif

launch:
	$(call progress_bar)

$(NAME):	$(OBJ) $(LIBNAME) $(MLXNAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIBNAME) $(MLXNAME) $(LDFLAGS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@) # 2> /dev/null || true
	$(CC) $(CFLAGS) $(MLXINC) $(LIBINC) -I$(INC) -c $< -o $@
	@printf "█"

$(LIBNAME):
	@printf "$(D)$(B)$(BLU)\n$(NAME) objects compiled\n\n$(D)"
	@$(MAKE) -C $(LIBPATH) CFLAGS+=-DWITH_OPEN=1

$(MLXNAME):
	@$(MAKE) -C $(MLXPATH) > /dev/null 2>&1 || true
	@printf "$(B)$(CYA)$(MLXNAME) compiled\n$(D)"

clean:
	@$(RM) $(OBJ_NAME)
	@$(MAKE) clean -C $(LIBPATH)
	@$(MAKE) clean -C $(MLXPATH) > /dev/null 2>&1 || true
	@echo "$(B)cleared$(D)"


fclean:		clean
	@$(RM) $(OBJ_PATH)
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBPATH)

re:			fclean all

.PHONY: all clean fclean re

# **************************************************************************** #

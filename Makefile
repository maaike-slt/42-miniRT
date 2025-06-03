# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msloot <msloot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 19:19:04 by msloot            #+#    #+#              #
#    Updated: 2025/06/03 20:45:54 by msloot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	miniRT
CC = 	cc
RM = 	rm -rf

CFLAGS =	-Wall -Werror -Wextra
CFLAGS +=	-g
# CFLAGS +=	-fsanitize=address

ASMFLAGS =	-MMD -MP
ASMINC =	-I./inc/

# LDFLAGS =
LDLIBS =	-lXext -lX11 -lm

# **************************************************************************** #
#	MAKEFILE	#

MAKEFLAGS += --silent

SHELL := bash

B =		$(shell tput bold)
I =		$(shell tput sitm)

BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)

D =		$(shell tput sgr0)
CLR =	$(shell tput el 1)

PRIMARY =	$(shell tput setaf 13)
SECONDARY =	$(GRE)

PROGRESS_START =	$(PRIMARY)▐
PROGRESS_END =		$(PRIMARY)▌
# PROGRESS_EMPTY =	-
PROGRESS_FILL =		$(SECONDARY)█

# **************************************************************************** #
#	LIBRARY	#

LIBFT_PATH =	./libft/
MLX_PATH =		./mlx/

LOCAL_LIB =		$(LIBFT_PATH)libft.a $(MLX_PATH)libmlx.a
ASMINC +=		-I$(LIBFT_PATH)inc/ -I$(MLX_PATH)inc/

LOCAL_LIB_PATH =	$(sort $(dir $(LOCAL_LIB)))

# **************************************************************************** #
#	SOURCE	#

SRC_PATH =	./src/
OBJ_PATH =	./obj/

SRC_NAME =	main.c \
			init/env.c init/pov.c init/object.c \
			parse/parse.c parse/parse_object.c \
			parse/preparse_object.c parse/count_object.c \
			parse/vec3.c parse/sphere.c parse/plane.c parse/cylinder.c \
			parse/triangle.c parse/square.c \
			parse/light.c parse/ambient_lighting.c \
			parse/resolution.c parse/camera.c parse/color.c \
			parse/puterr/line.c parse/puterr/identifier.c \
			parse/puterr/token_amount.c \
			parse/puterr/number.c parse/puterr/float.c \
			vec3_math/negate.c \
			vec3_math/add.c vec3_math/sub.c \
			vec3_math/scale.c vec3_math/dot.c vec3_math/cross.c \
			vec3_math/magnitude.c vec3_math/normalize.c \
			vec3_math/reflect.c \
			window/create.c window/close.c window/hook.c window/handle_keycode.c \
			render/render.c render/init.c render/set_pixel.c \
			render/pov_matrix.c render/ray_direction.c \
			render/color_ratio.c \
			render/light/compute.c render/light/ambient.c render/light/specular.c \
			render/intersect/all.c \
			render/intersect/sphere.c render/intersect/plane.c \
			render/intersect/cylinder.c render/intersect/cylinder_cap.c \
			render/intersect/keep_closest.c \
			puterr.c \
			free.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# *************************************************************************** #

define	progress_bar
	@printf "$(PROGRESS_START)$(D)"
	@i=0
	@while [[ $$i -lt $(words $(SRC)) ]] ; do \
		printf " " ; \
		((i = i + 1)) ; \
	done
	@printf "$(D)$(PROGRESS_END)$(D)\r$(PROGRESS_START)$(D)"
endef

name = 0

# *************************************************************************** #
#	RULES	#

all:	$(LOCAL_LIB) launch $(NAME)
	@if [ $(name) -ne 0 ]; then \
		printf "\n$(B)$(PRIMARY)─╴$(NAME) compiled$(D)\n"; \
	else \
		printf "\n$(B)$(PRIMARY)─╴$(D)$(B)$(I)nothing to do$(D)\n"; \
	fi

launch:
	$(call progress_bar)

$(NAME):	$(LOCAL_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(LOCAL_LIB) $(LDLIBS) -o $(NAME)
	@$(eval name=1)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(ASMFLAGS) $(ASMINC) -c $< -o $@
	@printf "$(D)$(PROGRESS_FILL)$(D)"

$(LOCAL_LIB):
	@$(MAKE) -C $(dir $@)

clean:	$(addsuffix .clean, $(LOCAL_LIB_PATH))
	@$(RM) $(OBJ_PATH) $(TEST_OBJ_PATH)
	@echo "$(B)cleared$(D)"

%.clean:
	@$(MAKE) clean -C $*

fclean:		clean $(addsuffix .fclean, $(LOCAL_LIB_PATH))
	@$(RM) $(NAME) $(TEST_NAME)

%.fclean:
	@$(MAKE) fclean -C $*

re:			fclean all

-include $(OBJ:.o=.d)

.PHONY: all clean fclean re launch

# **************************************************************************** #

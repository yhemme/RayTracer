# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:52:36 by cmalfroy          #+#    #+#              #
#    Updated: 2018/04/19 13:49:57 by thabdoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME ?= RT
CFLAGS += -Werror -Wextra -Wall
RCFLAGS = -O2 -fomit-frame-pointer
DCFLAGS = -g3 -DDEBUG
SCFLAGS = -fsanitize=address,undefined -ferror-limit=5
CC ?= gcc
MAKE += -j4

INC_PATH = includes
SRC_PATH = srcs
OBJ_DIR ?= obj
OBJ_PATH ?= obj/rel
3TH_PATH = .

LIBS = ft
ifneq (,$(findstring dev,$(NAME)))
LIB_NAME = $(addsuffix .dev, $(LIBS))
else ifneq (,$(findstring san,$(NAME)))
LIB_NAME = $(addsuffix .san, $(LIBS))
else
LIB_NAME = $(LIBS)
endif
LIB_NAME += mlx
3TH_NAME = libft
SRC_NAME = \
main.c vector_functs.c vector_functs2.c raytrace.c init.c \
ft_mlxlib.c sphere.c matrice_funct.c keyhook.c divers.c shadow.c plan.c \
cylinder.c cone.c vector_functs3.c parse.c fill.c parse_error.c divers3.c \
fill2.c fill3.c filters.c apply_filters.c save.c keyhook2.c chess.c \
pixel.c paraboloid.c hud.c divers2.c perlin.c reflection.c \
transparency.c perlin2.c wrap.c\

3TH = $(addprefix $(3TH_PATH)/, $(3TH_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
LNK = $(addprefix -L, $(3TH))
INC = $(addprefix -I, $(INC_PATH) $(addsuffix /include, $(3TH)))
LIB = $(addprefix -l, $(LIB_NAME))
DEP = $(OBJ:%.o=%.d)

all:
ifneq ($(3TH_NAME),)
	@+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th);)
endif
	@+$(MAKE) $(NAME) "CFLAGS = $(RCFLAGS)" "OBJ_PATH = $(OBJ_DIR)/rel"

dev:
ifneq ($(3TH_NAME),)
	@+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) dev;)
endif
	@+$(MAKE) $(NAME).dev "NAME = $(NAME).dev" "CFLAGS = $(DCFLAGS)" \
	  "OBJ_PATH = $(OBJ_DIR)/dev"

san:
ifneq ($(3TH_NAME),)
	@+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) san;)
endif
	@+$(MAKE) $(NAME).san "NAME = $(NAME).san" "CFLAGS = $(SCFLAGS)" \
	  "OBJ_PATH = $(OBJ_DIR)/san"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) $(LNK) $(OBJ) $(LIB) -o $(NAME) -framework AppKit -framework OpenGL
	@printf  "%-20s\033[32m✔\033[0m\n" "$(NAME): exe"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(shell dirname $@)
	@printf "\r%-20s$<\n" "$(NAME):"
	@$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@
	@printf "\033[A\033[2K"

clean:
ifneq ($(3TH_NAME),)
	@+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) clean;)
endif
	@rm -rf $(OBJ_PATH)
	@printf  "%-20s\033[32m✔\033[0m\n" "$(NAME): $@"

fclean:
ifneq ($(3TH_NAME),)
	@+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) fclean;)
endif
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@printf  "%-20s\033[32m✔\033[0m\n" "$(NAME): $@"

re: fclean all

-include $(DEP)

.PHONY: all, dev, san, $(NAME), clean, fclean, re

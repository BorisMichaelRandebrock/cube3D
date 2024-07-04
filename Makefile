# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 17:13:41 by fmontser          #+#    #+#              #
#    Updated: 2024/07/04 11:42:02 by fmontser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 		+= --silent
MAKEFILE		:= Makefile

INC_DIR			:= include/
SRC_DIR			:= src/
OBJ_DIR			:= obj/
BIN_DIR			:= bin/
RES_DIR			:= res/
NAME			:= cube3D
HDRS 			:=
SRCS 			:= main.c
OBJS			:= $(SRCS:.c=.o)
TEST_MAP		:= map.cub

MLX_DIR			:= src/minilibx-linux/
MLX_INC			:= src/minilibx-linux/
MLX_LIB			:= src/minilibx-linux/libmlx_Linux.a

CC_FLAGS		:= -Wall -Werror -Wextra -g -c
LIB_FLAGS		:= -lm -lX11 -lXext

CLEAN_TARGETS	= $(wildcard $(addprefix $(OBJ_DIR), $(OBJS)))
FCLEAN_TARGETS	= $(wildcard $(addprefix $(BIN_DIR), $(NAME)))

COLOR_GREEN		:=\033[0;32m
COLOR_RED		:=\033[0;31m
COLOR_BLUE		:=\033[0;34m
COLOR_END		:=\033[0m

vpath %.h $(INC_DIR) $(MLX_INC)
vpath %.c $(SRC_DIR)
vpath %.o $(OBJ_DIR)
vpath % $(BIN_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	@mkdir -p $(BIN_DIR)
	@gcc $(addprefix $(OBJ_DIR),$(OBJS)) $(MLX_LIB) -o $(BIN_DIR)$(NAME) $(LIB_FLAGS)
	@echo "$(COLOR_GREEN)write file: $(BIN_DIR)$(NAME)$(COLOR_END)"

$(MLX_LIB):
	@make -C $(MLX_DIR)

%.o : %.c $(HDRS) $(MAKEFILE)
	@mkdir -p $(OBJ_DIR)
	@gcc -I $(INC_DIR) -I $(MLX_INC) $(CC_FLAGS) $(LIB_FLAGS) $< -o $(OBJ_DIR)$@
	@echo "$(COLOR_GREEN)write file: $(OBJ_DIR)$@ $(COLOR_END)"

test: all
	@./$(BIN_DIR)$(NAME) $(RES_DIR)$(TEST_MAP)

clean:
	@$(foreach item,$(CLEAN_TARGETS),echo "$(COLOR_RED)delete file: $(item)$(COLOR_END)"; rm $(item);)

fclean: clean
	@$(foreach item,$(FCLEAN_TARGETS),echo "$(COLOR_RED)delete file: $(item)$(COLOR_END)"; rm $(item);)
	@make clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
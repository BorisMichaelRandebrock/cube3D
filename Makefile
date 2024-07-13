# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fran <fran@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 17:13:41 by fmontser          #+#    #+#              #
#    Updated: 2024/07/13 18:40:40 by fran             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 		+= --silent
MAKEFILE		:= Makefile

INC_DIR			:= include/
SRC_DIR			:= src/
OBJ_DIR			:= obj/
BIN_DIR			:= bin/
RES_DIR			:= res/
TESTS_DIR		:= tests/
NAME			:= cube3d
HDRS 			:= cube3d.h
SRCS 			:= main.c assets_manager.c
OBJS			:= $(SRCS:.c=.o)
TEST_MAP		:= level.cub

LIBFT_DIR		:= src/libft/
LIBFT_INC		:= src/libft/include/
LIBFT_LIB		:= src/libft/lib/libft.a

MLX_DIR			:= src/MLX42/
MLX_INC			:= src/MLX42/include/MLX42
MLX_LIB			:= src/MLX42/build/libmlx42.a
MLX_BUILD_DIR	:= src/MLX42/build/

CC_FLAGS		:= -Wall -Werror -Wextra -g -c
LIB_FLAGS		:= -lm -ldl -lglfw -pthread

CLEAN_TARGETS	= $(wildcard $(addprefix $(OBJ_DIR), $(OBJS)))
FCLEAN_TARGETS	= $(wildcard $(addprefix $(BIN_DIR), $(NAME)))

COLOR_GREEN		:=\033[0;32m
COLOR_RED		:=\033[0;31m
COLOR_BLUE		:=\033[0;34m
COLOR_END		:=\033[0m

vpath %.h $(INC_DIR) $(MLX_INC) $(LIBFT_INC)
vpath %.c $(SRC_DIR)
vpath %.o $(OBJ_DIR)
vpath % $(BIN_DIR)

all: $(NAME) $(LIBFT_LIB) $(MLX_LIB)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_BUILD_DIR) -j4

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@mkdir -p $(BIN_DIR)
	@gcc $(addprefix $(OBJ_DIR),$(OBJS)) $(MLX_LIB) $(LIBFT_LIB) -o $(BIN_DIR)$(NAME) $(LIB_FLAGS)
	@echo "$(COLOR_GREEN)write file: $(BIN_DIR)$(NAME)$(COLOR_END)"

$(MLX_LIB):
	@cmake $(MLX_DIR)-B $(MLX_BUILD_DIR)
	@make -C $(MLX_BUILD_DIR) -j4

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

%.o : %.c $(HDRS) $(MAKEFILE) $(LIBFT_LIB) $(MLX_LIB)
	@mkdir -p $(OBJ_DIR)
	@gcc -I $(INC_DIR) -I $(MLX_INC) -I $(LIBFT_INC) $(CC_FLAGS) $(LIB_FLAGS) $< -o $(OBJ_DIR)$@
	@echo "$(COLOR_GREEN)write file: $(OBJ_DIR)$@ $(COLOR_END)"

test: all
	@make test -C $(TESTS_DIR)

run: all
	@./$(BIN_DIR)$(NAME) $(RES_DIR)$(TEST_MAP)

clean:
	@$(foreach item,$(CLEAN_TARGETS),echo "$(COLOR_RED)delete file: $(item)$(COLOR_END)"; rm $(item);)

fclean: clean
	@$(foreach item,$(FCLEAN_TARGETS),echo "$(COLOR_RED)delete file: $(item)$(COLOR_END)"; rm $(item);)
	@make clean -C $(MLX_BUILD_DIR)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(TESTS_DIR)

re: fclean all

.PHONY: all clean fclean re

#TODO WRAP memory functions to guard.
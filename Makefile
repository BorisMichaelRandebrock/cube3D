# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 17:13:41 by fmontser          #+#    #+#              #
#    Updated: 2024/07/10 18:12:29 by fmontser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 		+= --silent
MAKEFILE		:= Makefile

INC_DIR			:= include/
SRC_DIR			:= src/
OBJ_DIR			:= obj/
BIN_DIR			:= bin/
RES_DIR			:= res/
NAME			:= cube3d
HDRS 			:= cube3d.h
SRCS 			:= main.c memutils.c strutils.c strutils2.c intutils.c assets_manager.c
OBJS			:= $(SRCS:.c=.o)
TEST_MAP		:= level.cub

MLX_DIR			:= src/MLX42/
MLX_INC			:= src/MLX42/include/MLX42
MLX_LIB			:= src/MLX42/build/libmlx42.a
MLX_BUILD		:= src/MLX42/build/

CC_FLAGS		:= -Wall -Werror -Wextra -g -c
LIB_FLAGS		:= -lm -ldl -lglfw -pthread

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



# git clone https://github.com/codam-coding-college/MLX42.git
# cd MLX42
# cmake -B build # build here refers to the outputfolder.
# cmake --build build -j4 # or do make -C build -j4


all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	@mkdir -p $(BIN_DIR)
	@gcc $(addprefix $(OBJ_DIR),$(OBJS)) $(MLX_LIB) -o $(BIN_DIR)$(NAME) $(LIB_FLAGS)
	@echo "$(COLOR_GREEN)write file: $(BIN_DIR)$(NAME)$(COLOR_END)"

$(MLX_LIB):
	@cmake src/MLX42 -B src/MLX42/build
	@make -C src/MLX42/build -j4

%.o : %.c $(HDRS) $(MAKEFILE)
	@mkdir -p $(OBJ_DIR)
	@gcc -I $(INC_DIR) -I $(MLX_INC) $(CC_FLAGS) $(LIB_FLAGS) $< -o $(OBJ_DIR)$@
	@echo "$(COLOR_GREEN)write file: $(OBJ_DIR)$@ $(COLOR_END)"

run: all
	@./$(BIN_DIR)$(NAME) $(RES_DIR)$(TEST_MAP)

clean:
	@$(foreach item,$(CLEAN_TARGETS),echo "$(COLOR_RED)delete file: $(item)$(COLOR_END)"; rm $(item);)

fclean: clean
	@$(foreach item,$(FCLEAN_TARGETS),echo "$(COLOR_RED)delete file: $(item)$(COLOR_END)"; rm $(item);)
	@make clean -C $(MLX_BUILD)

re: fclean all

.PHONY: all clean fclean re
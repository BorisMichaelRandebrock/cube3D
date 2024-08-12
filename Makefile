# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmontser <fmontser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 17:13:41 by fmontser          #+#    #+#              #
#    Updated: 2024/08/12 18:52:17 by fmontser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 		+=	--silent
MAKEFILE		:=	Makefile

INC_DIR			:=	include/
SRC_DIR			:=	src/
OBJ_DIR			:=	obj/
BIN_DIR			:=	bin/
RES_DIR			:=	res/
_DM_DIR			:=	$(SRC_DIR)_datamodel/
_MM_DIR			:=	$(SRC_DIR)_minimap/
_BG_DIR			:=	$(SRC_DIR)_background/
_UT_DIR			:=	$(SRC_DIR)_utils/
_PL_DIR			:=	$(SRC_DIR)_player/
_RC_DIR			:=	$(SRC_DIR)_raycast/
_WALL_DIR		:=	$(SRC_DIR)_walls/
_PIX_DIR		:=	$(SRC_DIR)_pixels/

RUN_MAP_NAME	:=	level_peninsula.cub

NAME			:=	cube3d
HDRS			:=	cube3d.h ansi.h tests.h respath.h rad.h
SRCS			:=	main.c free.c\
					ut_math.c ut_memory.c ut_print.c ut_lists.c ut_degrees.c\
					dm_setup.c dm_tilemap.c dm_load_colors.c dm_load_tex_path.c\
					dm_load_tilemap.c dm_check_tex_files.c dm_check_colors.c\
					dm_check_tilemap.c dm_load_player_data.c\
					pl_input.c pl_move.c\
					bg_setup.c\
					mm_setup.c mm_draw.c\
					rc_ray.c\
					wall_draw.c wall_setup.c\
					colors.c
OBJS			:=	$(SRCS:.c=.o)

TST_DIR		:=	$(SRC_DIR)test/
TST_NAME		:=	testing
TST_SRCS		:=	testing.c test_dm_load_colors.c test_dm_load_tex_path.c\
					test_dm_load_tilemap.c test_dm_check_tex_files.c\
					test_dm_check_colors.c test_dm_check_tilemap.c
TST_OBJS		:=	$(TST_SRCS:.c=.o)

LIBFT_DIR		:=	src/libft/
LIBFT_INC		:=	src/libft/include/
LIBFT_LIB		:=	src/libft/lib/libft.a

MLX_DIR			:=	src/MLX42/
MLX_INC			:=	src/MLX42/include/MLX42
MLX_LIB			:=	src/MLX42/build/libmlx42.a
MLX_BUILD_DIR	:=	src/MLX42/build/
MLX_FLAGS		:=	-B

CC_FLAGS		:=	-Wall -Werror -Wextra -g -c 
LIB_FLAGS		:=	-lm -ldl -lglfw -pthread 

CLEAN_TARGETS	=	$(wildcard $(addprefix $(OBJ_DIR), $(OBJS) $(TST_OBJS)))
FCLEAN_TARGETS	=	$(wildcard $(addprefix $(BIN_DIR), $(NAME) $(TST_NAME)))

COLOR_GREEN		:=	\033[0;32m
COLOR_RED		:=	\033[0;31m
COLOR_BLUE		:=	\033[0;34m
COLOR_END		:=	\033[0m

vpath %.h $(INC_DIR) $(MLX_INC) $(LIBFT_INC)
vpath %.c $(SRC_DIR) $(TST_DIR) $(_DM_DIR) $(_MM_DIR) $(_BG_DIR) $(_UT_DIR) $(_PL_DIR) $(_RC_DIR) $(_WALL_DIR) $(_PIX_DIR)
vpath %.o $(OBJ_DIR)
vpath % $(BIN_DIR)

all: $(NAME) $(LIBFT_LIB) $(MLX_LIB)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_BUILD_DIR) -j4

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@mkdir -p $(BIN_DIR)
	@gcc $(addprefix $(OBJ_DIR),$(OBJS) ) $(MLX_LIB) $(LIBFT_LIB) -o $(BIN_DIR)$(NAME) $(LIB_FLAGS)
	@echo "$(COLOR_GREEN)write file: $(BIN_DIR)$(NAME)$(COLOR_END)"

$(TST_NAME): $(filter-out main.o, $(OBJS)) $(TST_OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@mkdir -p $(BIN_DIR)
	@gcc $(addprefix $(OBJ_DIR),$(TST_OBJS) $(filter-out main.o, $(OBJS))) $(MLX_LIB) $(LIBFT_LIB) -o $(BIN_DIR)$(TST_NAME) $(LIB_FLAGS)
	@echo "$(COLOR_GREEN)write file: $(BIN_DIR)$(TST_NAME)$(COLOR_END)"

$(MLX_LIB):
	@cmake $(MLX_DIR) $(MLX_FLAGS) $(MLX_BUILD_DIR)
	@make -C $(MLX_BUILD_DIR) -j4

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

%.o : %.c $(HDRS) $(MAKEFILE) $(LIBFT_LIB) $(MLX_LIB)
	@mkdir -p $(OBJ_DIR)
	@gcc -I $(INC_DIR) -I $(MLX_INC) -I $(LIBFT_INC) $(CC_FLAGS) $(LIB_FLAGS) $< -o $(OBJ_DIR)$@
	@echo "$(COLOR_GREEN)write file: $(OBJ_DIR)$@ $(COLOR_END)"

test: $(TST_NAME)
	@./$(BIN_DIR)$(TST_NAME)

run: all
	@./$(BIN_DIR)$(NAME) $(RES_DIR)$(RUN_MAP_NAME)

valgrind: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(BIN_DIR)$(NAME) $(RES_DIR)$(RUN_MAP_NAME)

viking: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(BIN_DIR)$(NAME) $(RES_DIR)$(RUN_MAP_NAME)

clean:
	@$(foreach item,$(CLEAN_TARGETS),echo "$(COLOR_RED)delete file: $(item)$(COLOR_END)"; rm $(item);)

fclean: clean
	@$(foreach item,$(FCLEAN_TARGETS),echo "$(COLOR_RED)delete file: $(item)$(COLOR_END)"; rm $(item);)
	@make clean -C $(MLX_BUILD_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
MAKEFLAGS 		+= --silent
MAKEFILE		:= Makefile

INC_DIR			:= include/
SRC_DIR			:= src/
OBJ_DIR			:= obj/
BIN_DIR			:= bin/
T_INC_DIR		:= ../include/
T_SRC_DIR		:= ../src/
T_AM_DIR		:= ../src/assets_manager/
NAME			:= tests
HDRS 			:= tests.h cube3d.h libft.h
SRCS 			:= datamodel.c tests.c assets_manager_tests.c assets_manager.c utils.c\
					dm_load_colors.c dm_load_textures.c dm_load_tilemap.c
OBJS			:= $(SRCS:.c=.o)

CC_FLAGS		:= -Wall -Werror -Wextra -g -c

CLEAN_TARGETS	= $(wildcard $(addprefix $(OBJ_DIR), $(OBJS) $(TARGET_OBJS)))
FCLEAN_TARGETS	= $(wildcard $(addprefix $(BIN_DIR), $(NAME)))

LIBFT_DIR		:= ../src/libft/
LIBFT_INC		:= ../src/libft/include/
LIBFT_LIB		:= ../src/libft/lib/libft.a

COLOR_GREEN		:=\033[0;32m
COLOR_RED		:=\033[0;31m
COLOR_BLUE		:=\033[0;34m
COLOR_END		:=\033[0m

vpath %.h $(INC_DIR) $(T_INC_DIR) $(LIBFT_INC)
vpath %.c $(SRC_DIR) $(T_SRC_DIR) $(T_AM_DIR)
vpath %.o $(OBJ_DIR)
vpath % $(BIN_DIR)

all: $(NAME)
	@make -C $(LIBFT_DIR)
	
$(NAME): $(OBJS) $(LIBFT_LIB)
	@mkdir -p $(BIN_DIR)
	@gcc $(addprefix $(OBJ_DIR),$(OBJS)) $(LIBFT_LIB) -o $(BIN_DIR)$(NAME)
	@echo "$(COLOR_GREEN)write file: $(BIN_DIR)$(NAME)$(COLOR_END)"

%.o : %.c $(HDRS) $(MAKEFILE) $(LIBFT_LIB)
	@mkdir -p $(OBJ_DIR)
	@gcc -I $(INC_DIR) -I $(T_INC_DIR) -I $(LIBFT_INC) $(CC_FLAGS) $< -o $(OBJ_DIR)$@
	@echo "$(COLOR_GREEN)write file: $(OBJ_DIR)$@ $(COLOR_END)"

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

test: all
	@./bin/$(NAME)

clean:
	@$(foreach item,$(CLEAN_TARGETS),echo "$(COLOR_RED)delete file: $(item)$(COLOR_END)"; rm $(item);)

fclean: clean
	@$(foreach item,$(FCLEAN_TARGETS),echo "$(COLOR_RED)delete file: $(item)$(COLOR_END)"; rm $(item);)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
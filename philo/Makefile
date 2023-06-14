MANDATORY_DIR	=	srcs
BONUS_DIR		=	bonus
OBJ_DIR			=	.objs

SRCS			=	$(shell find $(MANDATORY_DIR) -name "*.c")
OBJS			=	$(patsubst $(MANDATORY_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# SRCS_BONUS		=	$(BONUS_DIR)/circles_utils_bonus.c	

OBJS_BONUS		=	$(patsubst $(BONUS_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS_BONUS))

HEADER_SRCS		=	philosophers.h
HEADERS_DIR		=	includes/
HEADERS			=	$(addprefix $(HEADERS_DIR), $(HEADER_SRCS))
CC				=	cc
RM				=	rm -f
# CFLAGS			=	-Wall -Wextra -Werror -o3
#MLX_INCLUDES	=	-I /usr/X11/include
MLX_LIB			=	-lpthread 
NAME			=	philo

GREEN			=	\033[1;32m
BLUE			=	\033[1;34m
RED				=	\033[1;31m
YELLOW      	=	\033[1;33m
DEFAULT			=	\033[0m
UP				=	"\033[A"
CUT				=	"\033[K"

$(OBJ_DIR)/%.o: $(MANDATORY_DIR)/%.c $(HEADERS) Makefile
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$<]$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf ${UP}${CUT}

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(HEADERS) Makefile
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$<]$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf ${UP}${CUT}

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX_LIB) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"

bonus: $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) -o $(NAME)
	@echo "$(GREEN)$(NAME) bonus compiled!$(DEFAULT)"

clean:
	@echo "$(RED)Cleaning build folder$(DEFAULT)"
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo "$(RED)Cleaning build folder$(DEFAULT)"
	@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
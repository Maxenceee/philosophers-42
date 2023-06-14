MANDATORY_DIR	=	srcs
OBJ_DIR			=	.objs

SRCS			=	$(MANDATORY_DIR)/checks.c	\
					$(MANDATORY_DIR)/freeing.c	\
					$(MANDATORY_DIR)/ft_atoi.c	\
					$(MANDATORY_DIR)/ft_bzero.c	\
					$(MANDATORY_DIR)/ft_calloc.c	\
					$(MANDATORY_DIR)/ft_eating.c	\
					$(MANDATORY_DIR)/ft_init.c	\
					$(MANDATORY_DIR)/ft_memset.c	\
					$(MANDATORY_DIR)/parsing.c	\
					$(MANDATORY_DIR)/philo_routine.c	\
					$(MANDATORY_DIR)/philosophers.c	\
					$(MANDATORY_DIR)/time.c	\
					$(MANDATORY_DIR)/utils.c
OBJS			=	$(patsubst $(MANDATORY_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

HEADER_SRCS		=	philosophers.h
HEADERS_DIR		=	includes/
HEADERS			=	$(addprefix $(HEADERS_DIR), $(HEADER_SRCS))
CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror
LIBS			=	-lpthread 
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

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"

clean:
	@echo "$(RED)Cleaning build folder$(DEFAULT)"
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)$(DEFAULT)"
	@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
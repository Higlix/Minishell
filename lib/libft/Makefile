DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET = [0m
BOLD = [1m

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIBFT_DIR = libft
LIBFT_PRINTER_DIR = libft_printer

SRC += $(wildcard $(SRC_DIR)/$(LIBFT_DIR)/*.c)
SRC += $(wildcard $(SRC_DIR)/$(LIBFT_PRINTER_DIR)/*.c)

OBJ += $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(INC_DIR)
NAME = libft.a

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $@
	@mkdir -p $@/$(LIBFT_DIR)
	@mkdir -p $@/$(LIBFT_PRINTER_DIR)
	@echo "$(MAGENTA)Object directories created..."

$(NAME): $(OBJ)
	@$(AR) -rcs $(NAME) $(OBJ)
	@echo "$(GREEN)Compiled { $(CYAN)$(NAME) $(GREEN)}$(WHITE)"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $< -o $@ $(CFLAGS)
	@echo "$(GREEN)Compiled {$(RED) $@ $(GREEN)}"

# test: all
# 	@gcc -I $(INC_DIR) test.c libft.a -o run_test
# 	@./run_test
# 	@rm -rf run_test

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Object directory $(RED)DELETED"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)$(NAME) $(RED)DELETED"

re: fclean all

.PHONY: all clean fclean re

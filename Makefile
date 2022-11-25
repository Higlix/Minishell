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
LIB_DIR = lib
LIBFT_DIR = libft

SRC += $(wildcard $(SRC_DIR)/*.c)
SRC += $(wildcard $(SRC_DIR)/env/*.c)
SRC += $(wildcard $(SRC_DIR)/utils/*.c)
SRC += $(wildcard $(SRC_DIR)/printer/*.c)
SRC += $(wildcard $(SRC_DIR)/lexer/*.c)
SRC += $(wildcard $(SRC_DIR)/token/*.c)
SRC += $(wildcard $(SRC_DIR)/signal/*.c)
OBJ += $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = gcc -g
CFLAGS = -Wall
INCLUDES = -I $(INC_DIR) -I /opt/homebrew/Cellar/readline/8.2.1/include -I $(LIB_DIR)/$(LIBFT_DIR)/$(INC_DIR)
LIBLRL = -lreadline -L /opt/homebrew/Cellar/readline/8.2.1/lib
LIBFT = $(LIB_DIR)/$(LIBFT_DIR)/libft.a
LIB = $(LIBFT) $(LIBLRL)

NAME = shell

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	mkdir -p $@
	mkdir -p $@/env
	mkdir -p $@/utils
	mkdir -p $@/printer
	mkdir -p $@/lexer
	mkdir -p $@/token
	mkdir -p $@/signal

$(LIBFT):
	make -C $(LIB_DIR)/$(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(CC) -o $@ $(OBJ) $(LIB)
	@echo "$(WHITE)-------------------------------------"
	@echo "$(YELLOW)Hedoshell Ready..."

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(WHITE)-------------------------------------"
	@$(CC) -c $^ -o $@ $(CFLAGS) $(INCLUDES)
	@echo "$(GREEN)Compiled {$(RED) $@ $(GREEN)}"

run: all
	@echo "\033[92m \033[3mRunning \033[0m \033[0m"
	@./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB_DIR)/$(LIBFT_DIR)

re: fclean all
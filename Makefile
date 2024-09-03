NAME = philo

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror -pthread -g #-fsanitize=thread

SRC_DIR = src

OBJ_DIR = obj

SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/create_philo.c \
		$(SRC_DIR)/utils_philo.c \
		$(SRC_DIR)/utils_general.c \
		$(SRC_DIR)/routines.c \
		$(SRC_DIR)/error_checks.c \
		$(SRC_DIR)/timecheck.c \
		$(SRC_DIR)/monitoring.c \
		$(SRC_DIR)/free_and_destroy.c

OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

RM = rm -rf

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Program ready!"

clean: 
	@$(RM) $(OBJ_DIR)
	@echo "Program cleaned successfully!"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
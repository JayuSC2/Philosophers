NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread -g #-fsanitize=address

SRCS =	src/main.c \
		src/init.c \
		src/create_philo.c \
		src/utils_philo.c \
		src/utils_general.c \
		src/routines.c \
		src/error_checks.c \
		src/timecheck.c \
		src/monitoring.c \
		src/free_and_destroy.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Program ready!"

clean: 
	@$(RM) $(OBJS)
	@echo "Program cleaned successfully!"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
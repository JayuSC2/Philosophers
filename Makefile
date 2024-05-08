NAME = philo

CC = CC

CFLAGS = -Wall -Wextra -Werror -g

SRCS =	src/main.c \
		src/philo.c \
		src/utils.c \
		src/routines.c \
		src/checks.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)
$(NAME): $(OBJS)
	@$(MAKE) -s -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)
	@echo "Program ready!"

clean: 
	@$(MAKE) -s -C ./libft fclean
	@$(RM) $(OBJS)
	@echo "Program cleaned successfully!"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
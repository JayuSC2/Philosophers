NAME = philo

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS =	src/main.c\
		src/philo.c\
		src/utils.c\
		src/routines.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)
$(NAME): $(OBJS)
	@$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Program ready!"

clean: 
	@$(RM) $(OBJS)
	@echo "Program cleaned successfully!"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
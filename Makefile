NAME = computorv1

SRCS_DIR = ./srcs/

SRCS =	main.c			\
		ft_putnbrf.c		\
		ft_putstr.c		\
		handle_float.c	\
		solve.c

OBJS_DIR = objs/

OBJ = $(SRCS:.c=.o)

OBJS = $(addprefix $(OBJS_DIR), $(OBJ))

FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling" $<
	@gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $(OBJS)
	@echo ""
	@echo "Exec computorv1 created !"
	@echo "usage: ./computorv1 [equation]"

all: $(NAME)

clean:
	@echo "Removing objs"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Removing exec"
	@rm -f $(NAME)

re: fclean all

test: all
	@sh test.sh

.PHONY:	all clean fclean re test

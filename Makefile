LIBFT = -L./libft/

LINK = -lft -lreadline

FLAGS = -g -fsanitize=address -Wall -Wextra -Werror 

CC = gcc -I./include/

RM = rm -f

NAME = minishell

SRC = 	./src/main.c\
		./src/built-ins/pwd.c\
		# ./src/args/is_inhibited.c ./src/args/parse.c\
		# ./src/args/replace_str.c ./src/args/split_args.c\
		# ./src/args/sub_env.c ./src/args/update.c\
		# ./src/utils/utils.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(LIBFT) $(LINK)

clean:
	-@echo "Removing object files..."
	make clean -C ./libft
	$(RM) $(OBJ)

fclean : clean
	-@echo "Removing executive file..."
	make fclean -C ./libft
	$(RM) $(NAME)

re : fclean all
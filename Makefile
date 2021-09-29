LIBFT = -L./libft/

LINK = -lft -lreadline

FLAGS = -fsanitize=address -Wall -Wextra -Werror

CC = gcc -g -I./include/

RM = rm -f

NAME = minishell

SRC = 	./src/main.c\
		./src/tokenizer/tokenizer.c\
		./src/utils/utils.c\
		./src/tokenizer/build_lexer.c\
		#./src/utils/utils_outside_project.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LINK)

clean:
	-@echo "Removing object files..."
	make clean -C ./libft
	$(RM) $(OBJ)

fclean : clean
	-@echo "Removing executive file..."
	make fclean -C ./libft
	$(RM) $(NAME)

re : fclean all

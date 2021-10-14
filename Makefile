LIBFT = -L./libft/

LINK = -lft -lreadline

FLAGS = -Wall -Wextra -Werror

CC = gcc -g -I./include/

RM = rm -f

NAME = minishell

SRC = 	./src/main.c\
		./src/tokenizer/tokenizer.c\
		./src/tokenizer/handle_variable.c\
		./src/tokenizer/parse_command.c\
		./src/tokenizer/build_lexer.c\
		./src/utils/utils.c\
		./src/utils/get_env_list.c\
		./src/utils/build_lexer_utils.c\
		./src/utils/handle_variable_utils.c\
		./src/utils/parse_command_utils.c\
		./src/utils/token_utils.c\
		./src/utils/utils_outside_project.c\
		./src/built-ins/exit.c ./src/built-ins/pwd.c ./src/built-ins/echo.c\
		./src/built-ins/env.c ./src/built-ins/unset.c ./src/utils/exec_coms_utils.c
		#./src/utils/utils_outside_project.c

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

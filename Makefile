LIBFT = -L./libft/

LINK = -lft -lreadline

FLAGS = -g -fsanitize=address -Wall -Wextra -Werror

CC = gcc -I./include/

RM = rm -f

NAME = minishell

SRC = 	./src/main.c\
		./src/built-ins/pwd.c\
		./src/built-ins/env.c\
		./src/utils/parse_env_to_linked_list.c\
		./src/utils/utils_outside_project.c\
		./src/utils/free_memory.c\
		./src/utils/is_shell_var.c\
		./src/args/is_inhibited.c ./src/args/parse.c\
		./src/args/remove_backslash_and_quote.c\
		./src/args/replace_str.c ./src/args/split_args.c\
		./src/args/sub_env.c ./src/args/sub_q.c ./src/args/sub_tilde.c\
		./src/args/type_args.c ./src/args/update.c\
		./src/cmds/add_calloc.c ./src/cmds/command_valid.c ./src/cmds/double_char.c\
		./src/cmds/free_command.c ./src/cmds/ft_is_in_set.c ./src/cmds/split_command.c\
		./src/redirection/double_left_chevron.c ./src/redirection/double_right_chevron.c\
		./src/redirection/is_simple.c ./src/redirection/multi_pipe.c ./src/redirection/redirection.c\
		./src/redirection/single_left_chevron.c ./src/redirection/single_right_chevron.c\
		./src/redirection/try_exec.c ./src/redirection/update_env.c\
		./src/utils/utils.c ./src/utils/error.c ./src/utils/redirection_utils.c ./src/utils/redirection_utils2.c\

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

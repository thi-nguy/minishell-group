# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 23:31:12 by idamouttou        #+#    #+#              #
#    Updated: 2021/10/11 22:17:43 by idamouttou       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
LIBFT = -L./Libft/

LINK = -lft -lreadline

FLAGS = -Wall -Wextra -Werror

CC = gcc -g -I./includes/

RM = rm -f

NAME = minishell

SRC		=	srcs/main.c \
				srcs/build/cd.c srcs/build/echo.c srcs/build/env.c srcs/build/exit.c \
				srcs/build/export.c srcs/build/pwd.c srcs/build/unset.c \
				srcs/excution/exec_coms.c srcs/excution/exec_pipe.c srcs/excution/exec_redir.c \
				srcs/excution/find_exec.c \
				srcs/parsing/converter.c srcs/parsing/parser.c srcs/parsing/sig_handlers.c srcs/parsing/token_to_ast.c \
				srcs/utils/env_utils.c srcs/utils/exec_coms_utils.c srcs/utils/list_utils.c srcs/utils/parser_utils.c srcs/utils/main_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		cd Libft/ && make && make bonus && make clean
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LINK)



clean:
	rm -f $(OBJ)
	

fclean: clean 
	rm -f $(NAME)
	cd Libft/ && make fclean

re: fclean all

.PHONY: all, clean, fclean, re

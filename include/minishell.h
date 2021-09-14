#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>

# include "../libft/libft.h"
# include "parsing.h"
# include "struct.h"

void    print_working_directory(t_command *cmd);
void	parse_env(t_command *command, char **env, int size);
t_env	*insert_at_beginning(t_env *head, char *data);
t_env	*add_to_empty(t_env *head, char *data);
void    print_list(t_env *head);
int     count_env_var(char **env);

#endif
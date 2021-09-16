#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "../libft/libft.h"
# include "struct.h"
# include "parsing.h"
# include "utils.h"

# define CHEVRON_LL '<' * '<'
# define CHEVRON_RR '>' * '>'
# define PIPE_PIPE '|' * '|'
# define AND_AND '&' * '&'

char    *print_working_directory(t_command *cmd);
void	parse_env(t_command *command, char **env, int size);
t_env	*insert_at_beginning(t_env *head, char *data);
t_env	*add_to_empty(t_env *head, char *data);
void    print_list(t_env *head);
int     count_env_var(char **env);
void	free_memory(t_env *env_list);
void    print_env_var(t_command *cmd);
void    parse_shell_var(t_command *command, char *line);
bool    is_shell_var(char *line);
bool    is_syntax_valid(char **table);
t_shell_var     *add_to_empty_var_list(t_shell_var *head, char **shell_var);
void        update_var(t_shell_var *head, char **shell_var);

#endif

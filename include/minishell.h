#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>

# include "../libft/libft.h"
# include "struct.h"
# include "global.h"


void        tokenizer(char *line, t_token **token_list);
t_token     *create_token(char c, e_type type);

void	    add_token_to_end(t_token **lst, t_token *new_token);
t_token	    *get_last_token(t_token *token_list);

void    	free_all_memory(t_token **head_token);
void	    free_all_memory_env(t_env **head_token);

int         build_lexer(t_token **token_list);
void        join_same_type_token(t_token *current_token);
void        remove_token_node(t_token *node);
int         handle_quote(t_token *current_token);
void        handle_variable(t_token *variable_token);
char        *get_variable_name(t_token *variable_token);
int         is_variable_valid(char *var_name);
char        *get_variable_value(char *var_name);

void        get_env_list(char **env);
t_env       *create_env(char *var);
void	    add_env_to_end(t_env *new_env);
t_env       *get_last_env(void);

// Functions outside of project.
void    print_item(t_token *token);


//command
int	my_pwd(void);
int	my_exit(char **tmp);
int	my_echo(char **line);
int	my_env(t_list *env);
int	my_unset(char **var, t_list *env);

//utils
void	exec_builtin(char *name, char **args, t_list *envlist);

#endif

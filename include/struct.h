#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env
{
	char			*data;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

typedef struct s_shell_var
{
    char                *var_name;
    char                *value;
    struct s_shell_var  *prev;
    struct s_shell_var  *next;
} t_shell_var;

typedef struct s_command
{
    char        *command_name;
    char        *command_option;
    char        *command_argument;
    t_env       *env_head;
    t_env       *env_end;
    t_shell_var *shell_var_head;
    t_shell_var *shell_var_end;

} t_command;


#endif

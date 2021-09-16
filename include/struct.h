#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env
{
	char			*data;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

typedef struct s_command
{
    char    *command_name;
    char    *command_option;
    char    *command_argument;
    t_env   *env_head;
    t_env   *env_end;

} t_command;


#endif

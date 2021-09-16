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
    int     end;
	int     type;
	char    *str;
	char    **args;
	int	    f_out;

} t_command;

typedef struct s_global
{
    int     return_code;
    char    **env;
}               t_global;

t_global	g_global;

typedef struct s_parsing
{
	bool	inhibited;
	bool	single_q;
	bool	double_q;
	bool	sp;
	bool	is_inhiber;
	bool	is_simple;
	bool	is_double;
}	t_parsing;

typedef struct t_fd
{
	int		end;
	int		f;
	int		stdin_;
	bool	first;
	int		stdout_;
	int		current_pipe[2];
	int		f_out;

}	t_fd;

#endif

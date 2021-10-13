#ifndef STRUCT_H
# define STRUCT_H

typedef enum		e_token_type
{
	redirect_input, // <
	double_redirect_input, // <<
	redirect_output, // >
	double_redirect_output, // >>
	pipe_symbol, // |
	single_quote, // '
	double_quote, // ""
	literal, // le reste
	variable, // $
	space,
	no_redirect
}					e_type;

typedef struct		s_token
{
	char			*value;
	e_type			type;
	struct s_token	*next;
	struct s_token 	*prev;
}					t_token;

typedef struct 		s_env
{
	char			*name;
	char			*value;
	struct s_env 	*next;
	struct s_env	*prev;
}					t_env;

typedef struct		s_command
{
	t_token				*command_line; // {"-n", "hello how are you", "lala"}
	char				*command; // echo, env, export, cd, pwd, unset
	char				*file_path; // file.txt
	e_type				redirect_type; // redirect_input (<)
}					t_command;




#endif

#ifndef STRUCT_H
# define STRUCT_H

typedef enum		e_token_type
{
	left_redirection, // <
	right_redirection, // >
	double_left_redirection,
	double_right_redirection,
	pipe_symbol, // |
	single_quote, // '
	double_quote, // ""
	literal, // le reste
	variable, // $
	space,
	question_mark  //?
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

typedef struct		s_info
{
	int				return_value;
}					t_info;



#endif

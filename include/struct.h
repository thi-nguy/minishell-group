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
}					t_token_type;

typedef struct		s_token
{
	void			*value; //pointer void quan trong e
	t_token_type	type; // khong duoc dung enum thi dung char* khong sao hoac int. literal
}					t_token;

typedef struct		s_token_list
{
	t_token					*content;
	struct s_token_list		*next;
	struct s_token_list		*prev;
}					t_token_list;

typedef struct		s_info
{
	t_token_list			*list_input;
	int						return_value;
}					t_info;

t_info				g_info;

#endif

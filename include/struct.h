#ifndef STRUCT_H
# define STRUCT_H

typedef enum		e_token_type
{
	left_redirection,
	right_redirection,
	double_left_redirection,
	double_right_redirection,
	pipe_symbol,
	single_quote,
	double_quote,
	literal,
	variable,
	space,
}					t_token_type;

typedef struct		s_token
{
	void			*value; //pointer void quan trong
	t_token_type	type; // khong duoc dung enum thi dung char* khong sao hoac int.
}					t_token;

typedef struct		s_info
{
	t_list			*list_input;
	int				return_value;
}					t_info;

t_info				g_info;

#endif

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

void    tokenizer(char *line, t_token *token_list);
t_token         *create_token(char c, e_type type);

void	add_token_to_end(t_token **lst, t_token *new_token);
t_token	*get_last_token(t_token *token_list);

//void	    free_all_memory(void);
//void        free_token(t_token *content);

//void        concat_same_type_token(void);
//void        join_same_type_token(t_token_list **token_list);
//int     handle_quote(t_list *input_list, t_token_type quote_type);

// Functions outside of project.
void    print_item(t_token *token);

#endif

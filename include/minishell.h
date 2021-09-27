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

void            tokenizer(char *line);
t_token_list	*get_last_token(t_token_list *lst);
void	        add_token_to_end_list(t_token_list **lst, t_token_list *new);
t_token_list	*make_new_token(void *content);

t_token     *create_token(char c, t_token_type type);
void	    free_all_memory(void);
void        free_token(t_token *content);

void        concat_same_type_token(void);
void        join_same_type_token(t_token_list **token_list);
//int     handle_quote(t_list *input_list, t_token_type quote_type);

// Functions outside of project.
void    print_item(t_token *token);

#endif

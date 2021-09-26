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

void        tokenizer(char *line);
t_token     *create_token(char c, t_token_type type);
void	    free_all_memory(void);
void        free_token(void *token);


// Functions outside of project.
void    print_item(void *token);

#endif

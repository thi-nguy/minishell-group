#include "minishell.h"

void    print_item(void *token)
{
    t_token *current_token;

    current_token = (t_token*)token;
    printf("token value: |%s| and its type: |%d|\n", (char*)current_token->value, current_token->type);
}
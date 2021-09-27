#include "minishell.h"

void    print_item(t_token *token)
{
    printf("token value: |%s| and its type: |%d|\n", token->value, token->type);
}

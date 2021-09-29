#include "minishell.h"

void    build_lexer(t_token **token_list)
{
    t_token *current_token;

    current_token = *token_list;
    while (current_token)
    {
        // Todo 1: if there is quote, handle quote till the next quote.
        //if (current_token->type == single_quote || current_token->type == double_quote)
        //    if (handle_quote(g_info.list_input, current_token->type) == -1)
        //        return ;

        // Todo 2: join same type tokens to one token (remember to handle double redirection >> <<)
        // ! remove the current node if join successfully.
        join_same_type_token(current_token);
        // Todo 3:

        current_token = current_token->next;
    }
}

void    join_same_type_token(t_token *current_token)
{
    t_token *prev_token;
    t_token *next_token;
    t_token *new_token;
    char    *new_value;

    if (current_token->prev == NULL)
        return ;
    prev_token = current_token->prev;
    next_token = current_token->next;
    if (prev_token->type != current_token->type)
        return ;
    new_value = ft_strjoin(prev_token->value, current_token->value);
    free(prev_token->value);
    prev_token->value = new_value;
    free(current_token->value);
    current_token->value = NULL;
    free(current_token);
    current_token = NULL;
    prev_token->next = next_token;
    if (next_token != NULL)
        next_token->prev = prev_token;
}


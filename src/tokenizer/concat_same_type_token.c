#include "minishell.h"

void    concat_same_type_token(void)
{
    t_token_list      *current_list;

    current_list = g_info.list_input;
    while (current_list)
    {
        // Todo 1: if there is quote, handle quote till the next quote.
        //if (current_token->type == single_quote || current_token->type == double_quote)
        //    if (handle_quote(g_info.list_input, current_token->type) == -1)
        //        return ;

        // Todo 2: join same type tokens to one token (remember to handle double redirection >> <<)
        // ! remove the current node if join successfully.
        join_same_type_token(&current_list);
        // Todo 3:

        current_list = current_list->next;
    }

}

void    join_same_type_token(t_token_list **token_list)
{
    t_token *prev_token;
    t_token *current_token;
    t_token *new_token;
    char    *new_value;

    if ((*token_list)->prev == NULL)
        return ;
    prev_token = (*token_list)->prev->content;
    current_token = (*token_list)->content;
    if (prev_token->type != current_token->type)
        return ;
    new_value = ft_strjoin(prev_token->value, current_token->value);
    //free((*token_list)->content->value);
    (*token_list)->content->value = new_value;
    free((*token_list)->prev->content);
    (*token_list)->prev->content = NULL;
    free((*token_list)->prev);
    (*token_list)->prev = NULL;
}

//int     handle_quote(t_list *input_list, t_token_type quote_type)
//{
//    // Todo 1: Delete the first token because it's a quote.

//    // Todo 2: Loop till finding the next quote, or till the end.
// //   handle_inside_quote(input_list->next, quote_type);



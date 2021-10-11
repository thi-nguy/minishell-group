#include "../../include/minishell.h"
/*
 Todo 1: if there is quote, handle quote till the next quote.
 Todo 1b: double handle redirection
 Todo 2: join same type tokens to one token (remember to handle double redirection >> <<)
 Todo 3: handle variable types.
*/

int    build_lexer(t_token **token_list)
{
    t_token *current_token;

    current_token = *token_list;
    while (current_token)
    {
        if (current_token->type == single_quote || current_token->type == double_quote)
            if (handle_quote(current_token) == -1)
                return (-1);
        if (current_token->type == variable)
        {
            handle_variable(current_token, 0);
            remove_token_node(current_token);
        }
        join_same_type_token(current_token);
        current_token = current_token->next;
    }
    return (1);
}

/*
Todo 1: handle other token types: change all to literal
Todo 2: handle variable type.
*/

int     handle_quote(t_token *quote_token)
{
    t_token *current_token;

    current_token = quote_token->next;
    while (current_token)
    {
        if (quote_token->type == current_token->type)
        {
            remove_token_node(quote_token); // delete the first quote
            remove_token_node(current_token); // delete the second quote
            return (1);
        }
        if (quote_token->type == double_quote && current_token->type == variable)
        {
            handle_variable(current_token, 1);
            remove_token_node(current_token);
        }
        if (quote_token->type == single_quote && current_token->type != literal) // change token type to literal because still inside quote.
            current_token->type = literal;
        if (current_token->type != literal && current_token->type != variable) // change token type to literal because still inside quote.
            current_token->type = literal;
        join_same_type_token(current_token); // join the current token to the previous
        current_token = current_token->next;
    }
    printf("Error: missing quotes\n");
    return (-1);
}

void       remove_token_node(t_token *node)
{
    t_token *prev_token;
    t_token *next_token;

    prev_token = node->prev;
    next_token = node->next;
    free(node->value);
    node->value = NULL;
    free(node);
    node = NULL;
    if (prev_token != NULL)
        prev_token->next = next_token;
    if (next_token != NULL)
        next_token->prev = prev_token;
}

void delete_node(t_token **head_ref, t_token *node)
{
   // If linked list is empty
   if (head_ref == NULL || *head_ref == NULL)
      return;
   // Store head node
   t_token *temp = *head_ref;
    // If head needs to be removed
    if (ft_strcmp(temp->value, node->value) == 1)
    {
        *head_ref = temp->next;
        if (*head_ref != NULL)   // Change head
            (*head_ref)->prev = temp;               // free old head
        free(temp);
        temp = NULL;
        return;
    }
    // Find previous node of the node to be deleted
    while (ft_strcmp(temp->value, node->value) != 1)
         temp = temp->next;
    // If position is more than number of nodes
    if (temp == NULL)
         return;
   remove_token_node(node);
}

void remove_token_node_2(t_token *node, t_token **head)
{
    t_token *temp;
    t_token *current;
    t_token *previous;

    if (ft_strcmp(node->value, (*head)->value) == 1)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    current = (*head)->next;
    previous = *head;
    while (current != NULL && previous != NULL) 
    {
        if (ft_strcmp(node->value, current->value) == 1)
        {
            temp = current;
            previous->next = current->next;
            free(temp);
            return;
        }
        previous = current;
        current = current->next;
    }
    return ;
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
    remove_token_node(current_token);
}

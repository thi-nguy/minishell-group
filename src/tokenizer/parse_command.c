#include "minishell.h"

int     parse_command(t_token **head_token, t_command **head_command)
{
    int     num_pipe;
    int     i;

    num_pipe = get_number_of_pipe(*head_token);
    *head_command = (t_command *)malloc(sizeof(t_command) + (num_pipe + 1));
    if (!*head_command)
        return (1);
    i = 0;
    while (i <= num_pipe)
    {
        (*head_command)[i].command_line = duplicate_token(head_token, i);
        i++;
    }
    return (0);
}

t_token     *create_token_node(char *str, e_type type)
{
    t_token *new_token;
    char    *value;

    value = ft_strdup(str);
    if (!value)
        return (NULL);
    new_token = (t_token*)malloc(sizeof(t_token));
    if (!new_token)
        return (NULL);
    new_token->value = value;
    new_token->type = type;
    new_token->next = NULL;
    new_token->prev = NULL;
    return (new_token);
}

t_token     *duplicate_token(t_token **head_token, int pipe_order)
{
    t_token     *new_head_token;
    t_token     *current_token;
    t_token     *new_token;
    int         current_pipe;

    current_token = *head_token;
    current_pipe = 0;
    while (current_token != NULL && current_pipe <= pipe_order && current_token->type != pipe_symbol)
    {
        if (current_token->type == pipe_symbol)
            current_pipe++;
        new_token = create_token_node(current_token->value, current_token->type);
        add_token_to_end(&new_head_token, new_token);
        current_token = current_token->next;
    }
    return (new_head_token);
}


int     get_number_of_pipe(t_token *head_token)
{
    t_token *current_token;
    int     i;

    i = 0;
    current_token = head_token;
    while (current_token->next)
    {
        if (current_token->type == pipe_symbol)
            i++;
        current_token = current_token->next;
    }
    return (i);
}

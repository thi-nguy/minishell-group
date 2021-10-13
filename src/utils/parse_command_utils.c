#include "../include/minishell.h"

void    init_redirection(t_command *head_command, int num_pipe)
{
    int i;

    i = 0;
    while (i <= num_pipe)
    {
        head_command[i].redirect_type = no_redirect;
        i++;
    }
}

int     get_number_of_pipe(t_token *head_token)
{
    t_token *current_token;
    int     i;

    i = 0;
    current_token = head_token;
    while (current_token)
    {
        if (current_token->type == pipe_symbol)
            i++;
        current_token = current_token->next;
    }
    return (i);
}

int     is_enough_command(t_command *head_command, int num_pipe)
{
    int i;

    i = 0;
    while (head_command[i].command_line != NULL)
        i++;
    if (i == num_pipe + 1)
        return (1);
    else
        return (0);
}

int     get_redirection_status(t_command *head_command)
{
    int i;
    int len;
    t_token *current_token;

    i = 0;
    while (head_command[i].command_line != NULL)
    {
        current_token = head_command[i].command_line;
        while(current_token->next != NULL)
        {
            len = ft_strlen(current_token->value);
            if (current_token->type == redirect_input)
                update_redirection_type(len, &head_command[i].redirect_type, &current_token->type, redirect_input);
            else if (current_token->type == redirect_output)
                update_redirection_type(len, &head_command[i].redirect_type, &current_token->type, redirect_output);
            current_token = current_token->next;
        }
        i++;
    }
    return (1);
}

int     update_redirection_type(int len, e_type *command_type, e_type *token_type, e_type new_type)
{
    if (len == 2)
    {
        *token_type = new_type + 1;
        *command_type = new_type + 1;
    }
    else if (len == 1)
        *command_type = new_type;
    else
        return (0);
    return (1);
}

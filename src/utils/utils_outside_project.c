#include "../../include/minishell.h"

void    print_item(t_token **head_token)
{
    t_token     *current_token;

    current_token = *head_token;
	while (current_token)
	{
		printf("Data node: |%s| - Type of data: |%d|\n", current_token->value, current_token->type);
		current_token = current_token->next;
	}
}

#include "minishell.h"

void    print_list(t_env *head)
{
    while (head != NULL)
    {
        printf("%s\n", head->data);
        head = head->next;
    }
}
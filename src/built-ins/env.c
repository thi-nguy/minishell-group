#include "../../include/minishell.h"

void    print_env_var(t_command *cmd)
{
    t_env *env_list;

    env_list = cmd->env_head;
    print_list(env_list);
}

void    print_list(t_env *head)
{
    while (head != NULL)
    {
        printf("%s\n", head->data);
        head = head->next;
    }
}

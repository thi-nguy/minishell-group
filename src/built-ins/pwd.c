#include "minishell.h"

char    *print_working_directory(t_command *cmd)
{
    t_env   *tmp;
    char    *path;

    tmp = cmd->env_head;
    while (tmp->next != NULL)
    {
        if (ft_strncmp(tmp->data, "PWD=", 4) == 0)
        {
            path = ft_strdup(tmp->data + 4);
            if (path != NULL)
                break ;
        }
        tmp = tmp->next;
    }
    return (path);
}

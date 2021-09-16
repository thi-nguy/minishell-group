
#include "../../include/minishell.h"

void    trim_args(char **args, const char *set)
{
    char *tmp;

    tmp = ft_strtrim(*args, set);
    free(*args);
    *args = tmp;

}
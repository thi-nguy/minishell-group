#include "minishell.h"

bool    is_shell_var(char *line)
{
    int     i;

    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '=')
            return (true);
        i++;
    }
    return (false);
}

char    **parse_shell_var(char *line)
{
    char    **split_result;
    int     len_var_name;
    int     len_var_value;

    split_result = ft_split(line, '=');
    len_var_name = ft_strlen(split_result[0]);
    len_var_value = ft_strlen(split_result[1]);
    if (split_result[0][len_var_name - 1] == ' ')
        return (NULL);
    if (split_result[1][0] != '"' || split_result[1][len_var_value - 1] != '"')
        return (NULL);
    return (split_result);
}

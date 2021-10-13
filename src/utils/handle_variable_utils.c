#include "../include/minishell.h"

int    is_variable_valid(char *var_name)
{
    t_env   *current_env;

    current_env = g_head_env;
    while (current_env)
    {
        if (ft_strcmp(var_name, current_env->name) == 1)
            return (1);
        current_env = current_env->next;
    }
    return (0);
}

int     get_total_len(char **split_result)
{
    int nb_words;
    int len;

    nb_words = 0;
    len = 0;
    while (split_result[nb_words] != NULL)
    {
        len += ft_strlen(split_result[nb_words]);
        nb_words++;
    }
    len += nb_words;
    return (len);
}

void    free_tab(char **str)
{
    int     i;

    i = 0;
    while (str[i] != NULL)
    {
        free(str[i]);
        str[i] = NULL;
        i++;
    }
    free(*str);
    *str = NULL;
}

char    *trim_space(char *str)
{
    char **split_result;
    char    *result;
    int len;
    int i;
    int j;

    split_result = ft_split(str, ' ');
    len = get_total_len(split_result);
    result = get_trimmed_string(split_result, len);
    free_tab(split_result);
    return (result);
}

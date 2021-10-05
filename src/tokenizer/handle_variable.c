#include "minishell.h"




int    is_variable_valid(char *var_name)
{
    //duyet qua list environment variable va tim ten.
    // Khong tim thay thi tra ve 0,
    // tim thay thi tra ve 1
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

char    *get_variable_value(char *var_name, int with_quote)
{
    t_env   *current_env;
    char    *result;

    current_env = g_head_env;
    while (current_env)
    {
        if (ft_strcmp(var_name, current_env->name) == 1)
        {
            if (with_quote == 1)
                return (current_env->value);
            else
            {
                result = trim_space(current_env->value);
                return (result);
            }

        }
        current_env = current_env->next;
    }
    return (NULL);
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

char    *get_trimmed_string(char **split_result, int len)
{
    char    *result;
    int     i;
    int     j;
    int     nb_words;

    result = (char *)malloc(sizeof(char) * len + 1);
    if (!result)
        return (NULL);
    nb_words = 0;
    j = 0;
    while (split_result[nb_words] != NULL)
    {
        if (nb_words != 0)
        {
            result[j] = ' ';
            j++;
        }
        i = 0;
        while (i < ft_strlen(split_result[nb_words]))
        {
            result[j] = split_result[nb_words][i];
            i++;
            j++;
        }
        nb_words++;
    }
    result[j] = '\0';
    return (result);
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

char    *get_variable_name(t_token *variable_token)
{
    t_token *current_token;

    current_token = variable_token->next;
    while (current_token)
    {
        if (current_token->type != literal)
        {
            return (variable_token->next->value);
        }
        join_same_type_token(current_token);
        current_token = current_token->next;
    }
    return (variable_token->next->value);
}

void    handle_variable(t_token *variable_token, int with_quote)
{
    char    *env_var_name;
    char    *env_var_value;

    env_var_name = get_variable_name(variable_token);
    if (ft_strcmp(env_var_value, "?") == 1)
        env_var_value = "$?";
    else if (is_variable_valid(env_var_name) == 0)
        env_var_value = "";
    else
        env_var_value = get_variable_value(env_var_name, with_quote);
    free(variable_token->next->value);
    variable_token->next->value = ft_strdup(env_var_value);
    //printf("variable name: |%s|\n", variable_token->next->value);
}


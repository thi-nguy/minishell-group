#include "minishell.h"


char    *get_variable_name(t_token *variable_token)
{
    t_token *current_token;

    current_token = variable_token->next;
    while (current_token)
    {
        if (current_token->type != literal)
        {
            return (current_token->prev->value);
        }
        join_same_type_token(current_token);
        current_token = current_token->next;
    }
    return (current_token->prev->value);
}

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

char    *get_variable_value(char *var_name)
{
    t_env   *current_env;

    current_env = g_head_env;
    while (current_env)
    {
        if (ft_strcmp(var_name, current_env->name) == 1)
        {
            return (current_env->value);
        }
        current_env = current_env->next;
    }
    return (NULL);
}

void    handle_variable(t_token *variable_token)
{
    char    *env_var_name;
    char    *env_var_value;

    env_var_name = get_variable_name(variable_token);
    if (is_variable_valid(env_var_name) == 0)
        env_var_value = "";
    else
        env_var_value = get_variable_value(env_var_name);
    free(variable_token->next->value);
    variable_token->next->value = ft_strdup(env_var_value);
    //printf("variable name: |%s|\n", variable_token->next->value);
}

#include "minishell.h"

void    get_env_list(char **env)
{
    int     i;
    t_env   *new_env;

    i = 0;
    while (i <= 1)
    {
        new_env = create_env(env[i]);
        if (!new_env)
            return ;
        add_env_to_end(new_env);
        i++;
    }
}

t_env   *create_env(char *var)
{
    t_env   *new_env;
    char    **split_result;
    char    *value;

    split_result = ft_split(var, '=');
    if (split_result == NULL)
        return (NULL);
    new_env = (t_env *)malloc(sizeof(t_env));
    if (!new_env)
        return (NULL);
    new_env->name = split_result[0];
    new_env->value = split_result[1];
    new_env->next = NULL;
    new_env->prev = NULL;
    return (new_env);
}

void	    add_env_to_end(t_env *new_env)
{
    t_env   *near_last;

    if (g_head_env == NULL)
    {
        g_head_env = new_env;
        return ;
    }
    near_last = get_last_env();
    near_last->next = new_env;
    new_env->prev = near_last;
}

t_env       *get_last_env(void)
{
    t_env   *current_env;

    current_env = g_head_env;
    if (current_env == NULL)
        return (NULL);
    while(current_env->next != NULL)
        current_env = current_env->next;
    return (current_env);
}
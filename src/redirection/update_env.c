/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:56:21 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/15 15:56:22 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

static bool is_set_env(char *env)
{
    int i;
    
    i = -1;
    while (g_global.env[++i] != 0)
    {
        if (ft_strncmp(g_global.env[i], env, ft_strlen(env)) == 0)
            return (true);
    }
    return (false);
}

void update_env(char *env, char *new_value)
{
    int i;
    char *tmp;

    i = 0;
    if (is_set_env(env))
    {
        tmp = ft_strdup(env);
        add_value(&tmp, "-");
        add_value(&tmp, new_value);
        while (g_global.env[i]
            && ft_strncmp(g_global.env[i], env, ft_strlen(env)) != 0)
            i++;
        free(g_global.env[i]);
        g_global.env[i] = ft_strdup(tmp);
        free(tmp);
    }
}
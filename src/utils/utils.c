/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:48:22 by idamoutto         #+#    #+#             */
/*   Updated: 2021/10/03 17:48:38 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_all_memory(t_token **head_token)
{
    t_token      *current_token;

    current_token = *head_token;

    if (*head_token != NULL)
    {
        while (current_token->next)
        {
            current_token = current_token->next;
            free(current_token->prev->value);
            current_token->prev->value = NULL;
            free(current_token->prev);
            current_token->prev = NULL;
        }
        free(current_token->value);
        current_token->value = NULL;
        free(current_token);
        current_token = NULL;
    }
}


void	free_all_memory_env(t_env **head_env)
{
    t_env      *current_env;

    current_env = *head_env;

    if (*head_env != NULL)
    {
        while (current_env->next)
        {
            current_env = current_env->next;
            free(current_env->prev->value);
            current_env->prev->value = NULL;
            free(current_env->prev->name);
            current_env->prev->name = NULL;
            free(current_env->prev);
            current_env->prev = NULL;
        }
        free(current_env->value);
        current_env->value = NULL;
        free(current_env->name);
        current_env->name = NULL;
        free(current_env);
        *head_env = NULL;
    }
}

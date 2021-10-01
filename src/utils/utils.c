/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:48:22 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/26 22:03:34 by thi-nguy         ###   ########.fr       */
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


void	free_all_memory_env(t_env **head_token)
{
    t_env      *current_token;

    current_token = *head_token;

    if (*head_token != NULL)
    {
        while (current_token->next)
        {
            current_token = current_token->next;
            free(current_token->prev->value);
            current_token->prev->value = NULL;
            free(current_token->prev->name);
            current_token->prev->name = NULL;
            free(current_token->prev);
            current_token->prev = NULL;
        }
        free(current_token->value);
        current_token->value = NULL;
        free(current_token->name);
        current_token->name = NULL;
        free(current_token);
        current_token = NULL;
    }
}
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

void	free_all_memory(void)
{
    t_token_list      *element;

    if (g_info.list_input)
    {
        while (g_info.list_input)
        {
            free_token(g_info.list_input->content);
            element = g_info.list_input;
            g_info.list_input = element->next;
            free(element);
            element = NULL;
        }
        g_info.list_input = NULL;
    }
}

void    free_token(t_token *content)
{

    t_token *current_token;

    if (!content)
        return ;
    current_token = content;
    if (current_token->value != NULL)
        ft_memdel(&current_token->value);
    free(current_token);
    current_token = NULL;
}

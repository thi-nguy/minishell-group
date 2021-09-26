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
    if (g_info.list_input)
    {
        ft_lstclear(g_info.list_input, free_token);
    }
}

void    free_token(void *content)
{

    t_token *current_token;

    if (!content)
        return ;
    current_token = (t_token *)content;
    if (current_token && current_token->value)
        ft_memdel(&current_token->value);
    free(current_token);
    current_token = NULL;
    content = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:58:44 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 13:58:47 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    free_command(t_command **command)
{
    int i;

    if (!command)
        return ;
    i = -1;
    while (command[++i])
    {
        if (command[i]->str)
            free(command[i]->str);
        if (command[i]->args)
            free_array(command[i]->args);
        free(command[i]);
    }
    free(command);
}

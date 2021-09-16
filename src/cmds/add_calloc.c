/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:49:52 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 13:49:54 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    add_calloc(t_command ***commandsp)
{
    int         count;
    t_command   **tmp;
    t_command   **command;

    command = *commandsp;
    count = -1;
    while (command[++count])
        ;
    tmp = ft_calloc(count + 2, sizeof(t_command *));
    count = -1;
    while (command[++count])
        tmp[count] = command[count];
    tmp[count] = ft_calloc(1, sizeof(t_command));
    free(command);
    *commandsp = tmp;
}

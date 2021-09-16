/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:20:05 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 16:20:06 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool simple_pipe(t_command **command, int *j)
{
    int i;

    i = *j;
    while (command[i + 1] && command[i + 1]->type == '|')
        i++;
    if (command[i + 1] && command[i + 1]->type != '|')
        return (false);
    return (true);
}

static bool simple_left(t_command **command, int *j)
{
    int i;

    i = *j;
    while (command[i + 1]
		&& (command[i + 1]->type == CHEVRON_LL || command[i + 1]->type == '<'))
        i++;
    if (command[i + 1]
        && (command[i + 1]->type != CHEVRON_LL || command[i + 1]->type != '<'))
        return (false);
    return (true);
    
}

static bool simple_right(t_command **command, int *j)
{
    int i;

    i = *j;
    while (command[i + 1]
        && (command[i + 1]->type == CHEVRON_RR || command[i + 1]->type == '>'))
        i++;
    if (command[i + 1]
        && (command[i + 1]->type != CHEVRON_RR || command[i + 1]->type != '>'))
        return (false);
    return (true);
}

bool is_simple(t_command **command, int *j)
{
    int i;

    i = *j;
    if (command[i + 1] && command[i + 1]->type == '|')
    {
        if (!simple_pipe(command, &i))
            return (false);
    }
    else if (command[i + 1]
        && (command[i + 1]->type == CHEVRON_RR || command[i + 1]->type == '>'))
    {
        if (!simple_right(command, &i))
            return (false);
    }
    else if (command[i + 1]
        && (command[i + 1]->type == CHEVRON_LL || command[i + 1]->type == '<'))
    {
        if (!simple_left(command, &i))
            return (false);
    }
    return (true);
}

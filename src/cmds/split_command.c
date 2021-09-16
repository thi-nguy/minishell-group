/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:31:09 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 14:31:11 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool try_create_command(char **strp, t_parsing *parsing,
    t_command ***commandsp, int *i)
{
    int type;
    char *str;

    str = *strp;
    if (!parsing->inhibited && !parsing->single_q && !parsing->double_q 
        && ft_is_in_set(*str, "<>|;&"))
    {
        add_calloc(commandsp);
        (*i)++;
        type = *str;
        if (double_char(*str, *(str + 1), "<>|&"))
        {
            type *= type;
            (*strp)++;
        }
        (*commandsp)[*i]->type = type;
        return (true);
    }
    return (false);
}

static void put_args(t_command **command)
{
    int i;

    if (!command)
        return ;
    i = -1;
    while (command[i]->str)
    {
        if (command[i]->str)
            command[i]->args = parsing(command[i]->str);
    }
}


t_command   **split_command(char *str)
{
    t_command   **command;
    t_parsing   parsing;
    int         i;

    i = 0;
    command = ft_calloc(2, sizeof(t_command *));
    command[i] = ft_calloc(1, sizeof(t_command));
    parsing = (t_parsing){0};
    while (*str)
    {
        update_struct2(*str, &parsing);
        if (!try_create_command(&str, &parsing, &command, &i))
            add_char(&command[i]->str, *str);
        str++;
    }
    if (!command_valid(command))
    {
        free_command(command);
        return (NULL);
    }
    put_args(command);
    return (command);
}

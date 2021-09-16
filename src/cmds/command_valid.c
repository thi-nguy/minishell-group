/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:01:33 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 22:01:35 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char *string_char(int nb)
{
    if (nb == CHEVRON_RR)
        return (">>");
    else if (nb == CHEVRON_LL)
        return ("<<");
    else if (nb == PIPE_PIPE)
        return ("||");
    else if (nb == AND_AND)
        return ("&&");
    else if (nb == '|')
        return ("|");
    else if (nb == '<')
        return ("<");
    else if (nb == '>')
        return (">");
    else if (nb == ';')
        return (";");
    else if (nb == '&')
        return ("&");
    return (NULL);
}

static bool first_command(t_command **command)
{
    char *str_error;

    if (command[1] && command[0]->type == 0 && command[0]->str == 0
        && command[1]->type != 0)
    {
        str_error = string_char(command[1]->type);
        ft_error("Synthax error", str_error, 2);
        return (false);
    }
    return (true);
}

static bool double_semicolon(t_command **command, int i)
{
    char *str_error;

    if (command[i + 1] && command[i]->type == ';' && command[i + 1]->type == ';'
        && !command[i]->str)
    {
        ft_error("Synthax error", ";;", 2);
        return (false);
    }
    else if (command[i]->type == ';')
        command[i]->type = 0;
    if (command[i + 1] && command[i]->type == 0 && command[i + 1]->type != 0
        && (ft_streql(command[i]->str, " ") || !command[i]->str))
    {
        str_error = string_char(command[i + 1]->type);
        ft_error("Synthax error", str_error, 2);
        return (false);
    }
    return (true);
}

static bool double_separator(t_command **command, int i)
{
    char *str_error;

    if (command[i + 1] && command[i]->type != 0
        && (ft_streql(command[i]->str, " ") || !command[i]->str))
    {
        str_error = string_char(command[i + 1]->type);
        ft_error("Synthax error", str_error, 2);
        return (false);
    }
    return (true);

}

bool command_valid(t_command **command)
{
    int i;

    i = -1;
    if (!first_command(command))
        return (false);
    while (command[++i])
    {
        if (command[i]->type == 0)
            continue ;
        if (!double_semicolon(command, i)
            || !double_separator(command, i))
                return (false);
    }
    if (!command[i - 1]->str && command[i - 1]->type)
    {
        printf("Error\n");
        return (false);
    }
    return (true);
}
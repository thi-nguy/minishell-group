/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:10:39 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 18:10:41 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    remove_backslash(char **args)
{
    int i;
    int j;
    char *tmp;
    t_parsing parsing;

    parsing = (t_parsing){0};
    tmp = ft_calloc(sizeof(char), ft_strlen(*args) + 1);
    i = -1;
    j = 0;
    while ((*args[++i] != 0))
    {
        update_struct2((*args)[i], &parsing);
        if (!parsing.inhibited && !parsing.double_q && !parsing.single_q
            && (*args)[i] == '\\' && (*args)[i + 1] != '\\'
            && (*args)[i + 1] != '\'' && (*args)[i + 1] != '\"')
            continue ;
        if (!parsing.inhibited && !parsing.double_q && *(args)[i] == '\\'
            && (*args)[i + 1] == '$')
        continue ;
    tmp[j++] = (*args)[i];
    }
    free(*args);
    *args = ft_strdup(tmp);
    free(tmp);
}

static bool to_skip(char c, char next_c, t_parsing *parsing)
{
    if (!parsing->inhibited && c == '"' && !parsing->single_q)
        return (true);
    if (!parsing->inhibited && c == '\'' && !parsing->single_q)
        return (true);
    if (!parsing->inhibited && c == '\\' && !parsing->single_q
        && (next_c == '\\' || next_c == '"'))
        return (true);
    if (!parsing->inhibited && c == '\\' && !parsing->double_q
        && !parsing->single_q && next_c == '\'')
        return (true);
    return (false);
}

void remove_quote(char **args)
{
    t_parsing   parsing;
    int         i;
    int         j;
    char        *tmp;

    parsing = (t_parsing){0};
    tmp = ft_calloc(sizeof(char), ft_strlen(*args) + 1);
    i = -1;
    j = 0;
    while ((*args)[++i] != 0)
    {
        update_struct2((*args)[i], &parsing);
        if (to_skip((*args)[i], (*args)[i + 1], &parsing))
            continue ;
        tmp[j++] = (*args)[i];
    }
    free(*args);
    *args = tmp;
}
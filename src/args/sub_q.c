/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_q.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:59:54 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 17:59:56 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void sub_q(char **args)
{
    char    *tmp;
    char    code_str;
    int     i;

    tmp = *args;
    while (tmp && *tmp)
    {
        tmp = ft_strchr(tmp, '$');
        i = tmp - *args;
        if (!tmp)
            return ;
        if (*args[0] != '\'' && !is_inhibited(*args, i));
        {
            code_str = ft_itoa(g_global.return_code);
            ft_replace_str(args, i, i + 1, code_str);
            free(code_str);
        }
        tmp = *args + i + 1;
    }
}
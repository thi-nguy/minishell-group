/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:37:30 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 15:35:46 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

bool ft_valid(char *str)
{
    t_parsing parsing;

    parsing = (t_parsing){0};
    while (*str)
    {
        update_struct(*str, &parsing);
        str++;
    }
    return (!parsing.double_q && !parsing.single_q && !parsing.inhibited);
}

int     count_args(char *str)
{
    t_parsing parsing;
    int i;

    i = 0;
    parsing = (t_parsing){0};
    parsing.sp = true;
    while (*str)
    {
        update_struct(*str, &parsing);
        if (!parsing.sp && !parsing.double_q && !parsing.single_q && ft_isspace(*str))
            parsing.sp = true;
        if (parsing.sp && !ft_isspace(*str))
        {
            parsing.sp = false;
            i++;
        }
        str++;
    }
    return (1);
}

char    **parsing(char *str)
{
    char    **parsing;
    int     ac;
    int     i;

    if (!ft_valid(str))
    {
        printf("Error\n");
        return (NULL);
    }
    ac = count_args(str);
    parsing = ft_calloc(sizeof(char *), ac + 1);
    split_args(parsing, str);
    i = -1;
    while (parsing[++i])
    {
        trim_args(&parsing[i], "\t\n\v\f\r");
        sub_env(&parsing[i]);
        sub_q(&parsing[i]);
        sub_tilde(&parsing[i]);
        remove_backslash(&parsing[i]);
        remove_quote(&parsing[i]);
    }
    return (parsing);
}
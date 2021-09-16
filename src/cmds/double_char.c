/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:56:34 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 13:56:35 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool    double_char(char c, char next_c, char *set)
{
    while (*set)
    {
        if (c == *set && next_c == *set)
            return (true);
        set++;
    }
    return (false);
}

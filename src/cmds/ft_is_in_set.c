/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:16:44 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 14:16:46 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool ft_is_in_set(char c, const char *set)
{
    while (*set)
    {
        if (*set == c)
            return (true);
        set++;
    }
    return (false);
}

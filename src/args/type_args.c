/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:43:12 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 17:43:13 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    type_args(char **args, const char *set)
{
    char *tmp;

    tmp = ft_strtrim(*args, set);
    free(*args);
    *args = tmp;

}
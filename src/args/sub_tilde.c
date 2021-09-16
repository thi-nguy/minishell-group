/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:06:01 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 18:06:04 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

void    sub_tilde(char **args)
{
    char    *tmp;

    if (*args[0] == 0 || (*args)[0] == '\'' || (*args)[0] == '"')
        return ;
    if ((*args[0] == '~' && (*args)[1] != '~' ))
    {
        tmp = ft_getenv("HOME");
        ft_replace_str(args, 0, 0, tmp);
        free(tmp);
    }
    
}
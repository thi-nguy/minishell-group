/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:30:53 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 13:30:55 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

void    ft_error(char *msg, char *error_msg, int error_code)
{
    g_global.return_code = error_code;
    ft_putstr_fd("minishell: ", 2);
    ft_putstr_fd(msg, 2);
    ft_putstr_fd("; ", 2);
    ft_putstr_fd(error_msg, 2);
    ft_putstr_fd('\n', 2);
}
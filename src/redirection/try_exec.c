/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:45:08 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/15 16:45:09 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

void try_exec(char **av)
{
    if (!av || !av[0])
        return ;
    else if (ft_strql(av[0], "env"))
        //build "env(av)";
    else if (ft_strql(av[0], "export"))
        //build "export(av)";
    else if (ft_strql(av[0], "unset"))
        //build "unsnet(av)";
    else if (ft_strql(av[0], "exit"))
        //build "exit(av)";
    else if (ft_strql(av[0], "pwd"))
        //build "pwd(av)";
    else if (ft_strql(av[0], "echo"))
        //build "echo(av)";
    else if (ft_strql(av[0], "cd"))
        //build "env(av)";
    else
        try_exec2
}
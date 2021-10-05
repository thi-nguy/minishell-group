/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_coms_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:51:09 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/05 16:25:24 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_builtin(char *name, char **args, t_list *envlist)
{
    int	i;

	i = 0;
	while (name[i])
	{
		name[i] = ft_tolower(name[i]);
		i++;
	}
	if (ft_strcmp("echo", name) == 0)
		g_excd_sig.excode = my_echo(args);
    if (ft_strcmp("exit", name) == 0)
		g_excd_sig.excode  = my_exit(args);
	if (ft_strcmp("pwd", name) == 0)
		g_excd_sig.excode = my_pwd();
	if (ft_strcmp("env", name) == 0)
		g_excd_sig.excode = my_env(envlist);
	if (ft_strcmp("unset", name) == 0)
		g_excd_sig.excode = my_unset(args, envlist);
}
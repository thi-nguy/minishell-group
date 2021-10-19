/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_coms_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:30:44 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/19 14:24:51 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_exit(void)
{
	if (errno == 2 || errno == 14)
	{
		if (errno == 2)
			ft_putstr_fd("No such file or directory\n", 2);
		if (errno == 14)
			ft_putstr_fd("Command not found\n", 2);
		exit(127);
	}
	if (errno == 13)
	{
		ft_putstr_fd("Permission denied\n", 2);
		exit(126);
	}
}

void	check_signal(int value)
{
	if (g_excd_sig.signal != 0)
	{
		g_excd_sig.signal = 0;
		g_excd_sig.excode = value;
	}
}

//file commence pas .

char	*handle_relative_case(char *fname, t_list *envlist)
{
	char	*slash;
	char	*res;
	char	*result;
	char 	*env_val;

	if (*fname != '.')
		return (NULL);
	slash = ft_strrchr(fname, '/');
	chdir(fname);
	res = getcwd(NULL, 0);
	env_val = get_env_val("PWD", envlist);
	chdir((const char*)env_val);
	result = ft_strjoin(res, slash);
	free(res);
	res = NULL;
	free(env_val);
	env_val = NULL;
	return (result);
}

//check A->Z
//check les nom des command
// excute chaque commande en fonction du nom

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
	if (ft_strcmp("export", name) == 0)
		g_excd_sig.excode = my_export(args, envlist);
	if (ft_strcmp("unset", name) == 0)
		g_excd_sig.excode = my_unset(args, envlist);
	if (ft_strcmp("cd", name) == 0)
		g_excd_sig.excode = my_cd(args, envlist);
	if (ft_strcmp("pwd", name) == 0)
		g_excd_sig.excode = my_pwd();
	if (ft_strcmp("env", name) == 0)
		g_excd_sig.excode = my_env(envlist);
	if (ft_strcmp("exit", name) == 0)
		g_excd_sig.excode = my_exit(args);
}

// si cd / cherche le repertoire
//check taille de array
// cas particulier avce les fichier .file
// 	signal(SIGQUIT, SIG_DFL); quit le programmme
//cree le file cherche le nom du file 

int	my_execve(char *file, char **args, t_list *envlist)
{
	char	*path;
	int		pid;
	char	**envarr;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, signal_handler);
	pid = fork();
	if (pid == 0)
	{	
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, signal_handler);
		envarr = listtoarr(envlist);
		if (*file == '.')
			path = handle_relative_case(file, envlist);
		else if (ft_strchr(file, '/'))
			path = file;
		else
			path = find_exec(envlist, file);
		delete_list(&envlist);
		execve(path, args, envarr);
		error_exit();
		exit(1);
	}
	return (pid);
}

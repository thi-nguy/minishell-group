/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_coms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:30:02 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/14 16:12:49 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//check les argument existe command permision et malloc

char	**collect_args(t_ast *self)
{
	char	**res;
	t_ast	*ptr;

	res = NULL;
	arraddelem(&res, "minishell");
	ptr = self->right;
	while (ptr != NULL)
	{
		arraddelem(&res, ptr->token);
		ptr = ptr->right;
	}
	return (res);
}

//initialisatin build presence de A->Z
//check le nom des command 

int	is_builtin(t_ast *self)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(self->token);
	while (tmp[i])
	{
		tmp[i] = ft_tolower(tmp[i]);
		i++;
	}
	i = 0;
	if (ft_strchr(self->token, '/'))
		return (0);
	if (ft_strcmp("echo", tmp) * ft_strcmp("export", tmp)
		* ft_strcmp("unset", tmp) * ft_strcmp("cd", tmp)
		* ft_strcmp("pwd", tmp) * ft_strcmp("env", tmp)
		* ft_strcmp("exit", tmp) == 0)
		i = 1;
	free(tmp);
	return (i);
}

//Script terminated by Control-C code 130
//code 131 controle  D

void	handle_chldsig(int status)
{
	if (WTERMSIG(status) == SIGQUIT)
	{
		ft_putstr_fd("Quit :3\n", 2);
		g_excd_sig.excode = 131;
	}
	if (WTERMSIG(status) == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		g_excd_sig.excode = 130;
	}
}

//excute le programme
//attend que le processus change detat
//appel fonction c+d et C+C

void	get_exit_code(char *token, char **args, t_list *envlist)
{
	int	pid;
	int	status;

	pid = my_execve(token, args, envlist);
	waitpid(pid, &status, 0);
	handle_chldsig(status);
	if (g_excd_sig.excode < 130 || g_excd_sig.excode > 132)
		g_excd_sig.excode = WEXITSTATUS(status);
}

//demarage des execution 
// trim Supprime tous les caractères correspondant 
//à un espace blanc au début et à la fin de la chaîne actuelle
//sauf quan dil ya un single ou double quote
//check les argument et malloc
//is builltin check le nom des command
//appel chaque command avec leur fonction 
//get exit code = controle d et c 

void	cmd_exec(t_ast *self, t_list *envlist)
{
	char	**args;
	int		i;

	i = 0;
	self->token = ft_quottrim(self->token);
	args = NULL;
	args = collect_args(self);
	while (args[i] != NULL)
	{
		args[i] = ft_quottrim(args[i]);
		i++;
	}
	if (is_builtin(self))
		exec_builtin(self->token, args, envlist);
	else
		get_exit_code(self->token, args, envlist);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
	free_arr(args);
}

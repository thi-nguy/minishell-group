/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:29:10 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/19 15:22:16 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_en_var(t_list *var, char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (((char *)var->content)[i] != '=')
		i++;
	((char *)var->content)[i + 1 ] = '\0';
	res = ft_strjoin(((char *)var->content), str);
	free(var->content);
	var->content = res;
}

void	change_var(t_list *envlist, char *newvar, char *varname)
{
	t_list	*ptr;

	ptr = envlist;
	while (ptr != NULL)
	{
		if (ft_strncmp((char *)ptr->content, varname, ft_strlen(varname)) == 0)
		{
			change_en_var(ptr, newvar);
		}
		ptr = ptr->next;
	}
}

//si pas de dossier error

int	handle_inval_cd(char *path, char *oldpwd)
{
	write(2, "cd: no such file or directory: ", 32);
	write(2, path, ft_strlen(path));
	write(1, "\n", 1);
	free(oldpwd);
	return (1);
}

//si cd $= va dans users
//cd /HOME va dans home
// cd seul affiche le repertoire courrant
//getcwd = obtenir le repertoire courant
//chdir change le repertoire courant
//change dadrresse de repertoire
//nouveau pwd

int	is_arg_valid(char **path)
{
	int i;
	
	i = 0;
	while (path[i] != NULL)
		i++;
	if (i > 1)
		return (0);
	return (1);
}

int	my_cd(char **path, t_list *envlist)
{
	int		ch;
	char	*tmp;
	char	*oldpwd;

	if (is_arg_valid(path) == 0)
	{
		printf("cd: too many arguments\n");
		return (1);
	}
	path++;
	if (*path == NULL)
		tmp = get_env_val("HOME", envlist);
	else
		tmp = ft_strdup(*path);
	tmp = skip_char(tmp, ' ');
	oldpwd = getcwd(NULL, 0);
	ch = chdir(tmp);
	free(tmp);
	tmp = NULL;
	if (ch < 0)
		return (handle_inval_cd(*path, oldpwd));
	change_var(envlist, oldpwd, "OLDPWD");
	free(oldpwd);
	tmp = getcwd(NULL, 0);
	change_var(envlist, tmp, "PWD");
	free(tmp);
	tmp = NULL;
	return (0);
}

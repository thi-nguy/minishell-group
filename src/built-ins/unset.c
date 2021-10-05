/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:06:56 by idamoutto         #+#    #+#             */
/*   Updated: 2021/10/05 16:25:21 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//efface les paramettre apres le egale de la variable
//et free
int	unset_one(char *var, t_list *env)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (env->next != NULL)
	{
		i = 0;
		while (((char *)env->next->content)[i] != '=')
			i++;
		if (ft_strncmp((char *)env->next->content, var, i) == 0)
		{
			tmp = env->next;
			env->next = env->next->next;
			free(tmp->content);
			free(tmp);
			return (1);
		}
		env = env->next;
	}
	return (1);
}
//check argument apres command unset error
//unset = Nom varriable error pour le = mais excute la command
int	my_unset(char **var, t_list *env)
{
	if (var[1] == NULL)
	{
		printf("unset: not enough arguments\n");
		return (1);
	}
	else if (*var[1] == '=' || *var[1] == '.')
	{
		printf("unset: =: invalid parameter name\n");
		unset_one(*var, env);
		var++;
	}
	while (*var != NULL)
	{
		unset_one(*var, env);
		var++;
	}
	return (0);
}
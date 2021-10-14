/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:30:21 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/09 02:53:40 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//list ajout arriere ajout la fin malloc content return res
//ft_lst_new creation du 1er noeud 
// ft_lstadd back fonction qui ajoute un nouveau noeud a larriere 
t_list	*converter(char **envp)
{
	int		i;
	t_list	*head;

	head = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(envp[i])));
		i++;
	}
	return (head);
}

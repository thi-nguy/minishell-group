/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:34:06 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/14 00:04:16 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//argument apres env si env = env ?=s s sort la liste
//env $= nimporte quel arguemnt sort la liste
//cd $= sort du dossier va dans repertoire courant
// cd /HOME idemd	

char	*get_env_val(char *env_name, t_list *envlist)
{
	t_list	*ptr;
	char	*equal_pos;

	if (*env_name == '?')
		return (ft_itoa(g_excd_sig.excode)); //converti un int en string
	ptr = envlist;
	while (ptr)
	{
		equal_pos = ft_strchr((char *)ptr->content, '='); //env = sort la liste
		*equal_pos = '\0';
		if (0 == ft_strcmp(env_name, ptr->content))
		{
			*equal_pos = '=';
			return (ft_strdup(equal_pos + 1));
		}
		*equal_pos = '=';
		ptr = ptr->next;
	}
	return ("\0");
}

int	find_symbol(char *str, char sym)
{
	int	res;

	res = 0;
	while (str[res] != '\0' && str[res] != sym)
	{
		res++;
	}
	if (str[res] == '\0')
		return (-1);
	return (res);
}

//check le = si pas de = sort le liste de varibla oblige de  mettre declare x sinon lors
//lajout dune nouvelle variable pb
void	print_all_sorted(t_list *sorted)
{
	int	i;

	while (sorted != NULL)
	{
		i = find_symbol(sorted->content, '=');
		((char *)sorted->content)[i] = '\0';
		printf("declare -x %s%s%s%s\n", (char *)sorted->content, "=\"",
			&((char *)sorted->content)[i + 1], "\"");
		((char *)sorted->content)[i] = '=';
		sorted = sorted->next;
	}
}

//lstnew malloc content
//ajout new env
//check export avec ou sans argument
//free export
void	print_sorted(t_list *env)
{
	t_list	*sorted;
	t_list	*tmp;
	t_list	*free_sort;

	if (env)
	{
		tmp = env;
		sorted = ft_lstnew(tmp->content);
		tmp = tmp->next;
		while (tmp != NULL)
		{
			ft_lstadd_front(&sorted, ft_lstnew(tmp->content));
			tmp = tmp->next;
		}
		free_sort = sorted;
		print_all_sorted(sorted);
	}
	ft_lstclear(&free_sort, free);
}

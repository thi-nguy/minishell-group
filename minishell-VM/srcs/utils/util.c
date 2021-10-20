/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:31:04 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/20 10:56:29 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_valid_str(char *str)
{
	if (!str)
		my_exit(NULL);
	if (ft_strlen(str) > 0)
		add_history(str);
	else
		return (0);
	if (!check_quotes(str))
	{
		printf("synthax error quote not closed\n");
		return (0);
	}
	return (1);
}

char	*get_tmp(char *path, t_list *envlist)
{
	char	*tmp;

	if (path == NULL)
		tmp = get_env_val("HOME", envlist);
	else
		tmp = ft_strdup(path);
	tmp = skip_char(tmp, ' ');
	return (tmp);
}

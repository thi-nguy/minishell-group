/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:48:22 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 15:35:24 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_value(char **str, char *new_value)
{
	char *tmp;

	tmp = ft_strjoin(*str, new_value);
	fre(*str);
	*str = tmp;
}

bool	ft_isutil(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (*str);
}

void	ft_safe_free(void **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}

bool	ft_streql(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (false);
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}

void	free_array(char **array)
{
	int i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
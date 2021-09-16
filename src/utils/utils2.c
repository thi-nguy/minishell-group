/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:39:58 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/16 13:40:08 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_suffix(char *str, char *suffix)
{
	int	size_suffix;
	int	size_str;

	size_suffix = ft_strlen(suffix) - 1;
	size_str = ft_strlen(str) - 1;
	if (size_str >= size_suffix)
	{
		while (size_suffix >= 0)
		{
			if (str[size_str] == suffix[size_suffix])
			{
				size_str--;
				size_suffix--;
			}
			else
				return (false);
		}
		return (true);
	}
	return (false);
}

char	**ft_get_paths(void)
{
	char	*path;
	char	**paths;

	path = ft_getenv("PATH");
	paths = ft_split(path, ':');
	free(path);
	return (paths);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:56:32 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 15:35:38 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *str)
{
	char	*name;
	char	*content;
	int		i;
	int		i_tmp;

	i = -1;
	while (g_global.env[++i])
	{
		i_tmp = 0;
		while (g_global.env[i][i_tmp] != '=')
			i_tmp++;
		name = ft_calloc(sizeof(char), i_tmp + 1);
		content = ft_calloc(1, ft_strlen(g_global.env[i]) - i_tmp + 1);
		ft_strlcpy(name, g_global.env[i], i_tmp + 1);
		ft_strlcpy(content, g_global.env[i] + i_tmp + 1,
			ft_strlen(g_global.env[i]) - i_tmp);
		if (ft_streql(str, name))
		{
			free(name);
			return (content);
		}
		free(name);
		free(content);
	}
	return (0);
}

char	*extract_env_name(const char *str)
{
	int		i;
	char	*env_name;

	str++;
	if (*str == 0)
		return (NULL);
	i = 0;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	if (!i)
		return (NULL);
	env_name = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(env_name, str, i + 1);
	return (env_name);
}

void	sub_env(char **args)
{
	char	*tmp;
	char	*env_name;
	char	*env_value;
	int		i;

	tmp = *args;
	while (tmp && *tmp)
	{
		tmp = ft_strchr(tmp, '$');
		i = tmp - *args;
		if (!tmp)
			return ;
		if (*args[0] != '\'' && !is_inhibited(*args, i))
		{
			env_name = extract_env_name(tmp);
			if (env_name)
			{
				env_value = ft_getenv(env_name);
				ft_replace_str(args, i, i + ft_strlen(env_name), env_value);
				free(env_value);
				free(env_name);
			}
		}
		tmp = *args + i + 1;
	}
}

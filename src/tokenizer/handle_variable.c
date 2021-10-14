/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:36:14 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/10/14 11:39:24 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_variable_value(char *var_name, int with_quote)
{
	t_env	*current_env;
	char	*result;

	current_env = g_head_env;
	while (current_env)
	{
		if (ft_strcmp(var_name, current_env->name) == 1)
		{
			if (with_quote == 1)
				return (current_env->value);
			else
			{
				result = trim_space(current_env->value);
				return (result);
			}
		}
		current_env = current_env->next;
	}
	return (NULL);
}

char	*get_trimmed_string(char **split_result, int len)
{
	char	*result;
	int		i;
	int		j;
	int		nb_words;

	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	nb_words = 0;
	j = 0;
	while (split_result[nb_words] != NULL)
	{
		if (nb_words != 0)
		{
			result[j] = ' ';
			j++;
		}
		i = 0;
		while (i < ft_strlen(split_result[nb_words]))
		{
			result[j] = split_result[nb_words][i];
			i++;
			j++;
		}
		nb_words++;
	}
	result[j] = '\0';
	return (result);
}

char	*get_variable_name(t_token *variable_token)
{
	t_token	*current_token;

	current_token = variable_token->next;
	while (current_token)
	{
		if (current_token->type != literal)
		{
			return (variable_token->next->value);
		}
		join_same_type_token(current_token);
		current_token = current_token->next;
	}
	return (variable_token->next->value);
}

void	handle_variable(t_token *variable_token, int with_quote)
{
	char	*env_var_name;
	char	*env_var_value;

	env_var_name = get_variable_name(variable_token);
	if (ft_strcmp(env_var_name, "?") == 1)
		env_var_value = get_variable_value("EXIT_CODE", with_quote);
	else if (is_variable_valid(env_var_name) == 0)
		env_var_value = "";
	else
		env_var_value = get_variable_value(env_var_name, with_quote);
	free(variable_token->next->value);
	variable_token->next->value = ft_strdup(env_var_value);
}

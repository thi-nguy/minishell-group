/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:30:25 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/19 21:43:25 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//si ptr = $

char	*replace_one(char *input, char *ptr, t_list *envlist, int dquot)
{
	char	*before;
	char	*after_env;
	char	*env_val;
	char	*first;
	char	*result;

	before = ft_substr(input, 0, ptr - input);
	after_env = get_after_env(ptr);
	env_val = env_val_name(input, ptr, after_env, envlist);
	first = ft_strjoin(before, env_val);
	if (*env_val)
	{
		free(env_val);
		env_val = NULL;
	}
	after_env = ft_strdup(after_env);
	env_val = replace_envs(after_env, envlist, dquot);
	if (input)
		free(input);
	result = ft_strjoin(first, env_val);
	free_str(&before, &first, &after_env, &env_val);
	return (result);
}

//check les quote apres la command env
// ptr = $
//si < sort la liste > saut a la ligne 

char	*replace_envs(char *input, t_list *envlist, int dquot)
{
	char	*ptr;
	char	*result;

	if (!input)
		return (NULL);
	ptr = input;
	while (*ptr)
	{
		if (*ptr == '\"')
			dquot = !dquot;
		else if (*ptr == '\'' && !dquot)
		{
			ptr = ft_strchr(ptr + 1, '\'');
			ptr++;
			continue ;
		}
		if (*ptr == '<' && *(ptr + 1) == '<' && !dquot)
			ptr += 3;
		if (*ptr == '$')
		{
			result = replace_one(input, ptr, envlist, dquot);
			return (result);
		}
		ptr++;
	}
	result = ft_strdup(input);
	return (result);
}

//alloue la memoire et check si les argument existe

char	*add_token(char ***arr_tokens, char *input, char *start, char *end)
{
	char	*res;

	res = ft_substr(input, start - input, end - start + 1);
	arraddelem(arr_tokens, res);
	free(res);
	return (end + 1);
}

//retour char de caractere string

char	*skip_char(char *str, char sym)
{
	while (*str == sym)
		str++;
	return (str);
}

//skip la chaine de caractere check la memoire et alloue et check
//les error de command

char	*split_to_tokens(char *input, char ***arr_tokens)
{
	char	*start_of_token;
	char	*end_of_token;

	start_of_token = input;
	while (*start_of_token != '\0')
	{
		start_of_token = skip_char(start_of_token, ' ');
		end_of_token = start_of_token;
		while (!ft_strchr("> <|\0", *(start_of_token)))
		{
			if (ft_strchr("\"\'", *end_of_token))
				end_of_token = ft_strchr(end_of_token + 1, *end_of_token);
			if (ft_strchr("> <|\0", *(end_of_token + 1)))
				break ;
			end_of_token++;
		}
		if (ft_strchr("<>", *start_of_token) && *start_of_token
			== *(start_of_token + 1))
			end_of_token++;
		if (*start_of_token != '\0')
			start_of_token = add_token(arr_tokens,
					input, start_of_token, end_of_token);
	}
	return (NULL);
}

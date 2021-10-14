/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:30:25 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/09 02:21:30 by idamouttou       ###   ########.fr       */
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
	char	*second;

	before = ft_substr(input, 0, ptr - input); //return seg chaine
	after_env = get_after_env(ptr);//check $? ok si error pour >< | single quote mais ok si double
	env_val = env_val_name(input, ptr, after_env, envlist);// env $=argument sort la liste ou env ?= sort la liste return env_val
	first = ft_strjoin(before, env_val);
	after_env = ft_strdup(after_env);
	second = replace_envs(after_env, envlist, dquot);//check les double quote et si env ?=<salut sort la liste mais si env ?=>salut saut a la ligne
	if (input)
		free(input);
	input = ft_strjoin(first, second);
	if (*env_val)
		free(env_val);
	free(second);
	free(first);
	free(before);
	return (input);
}
//check les quote apres la command env
// ptr = $
//si < sort la liste > saut a la ligne 
char	*replace_envs(char *input, t_list *envlist, int dquot)
{
	char	*ptr;

	if (!input)
		return (NULL);
	ptr = input;
	while (*ptr)
	{
		if (*ptr == '\"')
			dquot = !dquot;
		else if (*ptr == '\'' && !dquot)
		{
			ptr = ft_strchr(ptr + 1, '\''); //cherche le caractere
			ptr++;
			continue ;
		}
		if (*ptr == '<' && *(ptr + 1) == '<' && !dquot)
			ptr += 3;
		if (*ptr == '$')
			return (replace_one(input, ptr, envlist, dquot));
		ptr++;
	}
	return (input);
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
//skip la chaine de caractere check la memoire et alloue et check les error de command
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
	free(input);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:44:18 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/10/14 11:47:48 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_type	get_token_type(char c)
{
	if (c == '>')
		return (redirect_output);
	else if (c == '<')
		return (redirect_input);
	else if (c == '|')
		return (pipe_symbol);
	else if (c == '\'')
		return (single_quote);
	else if (c == '"')
		return (double_quote);
	else if (c == ' ' || c == '\t' || c == '\f' || c == '\r' || c == '\v')
		return (space);
	else if (c == '$')
		return (variable);
	else
		return (literal);
}

t_token	*get_last_token(t_token *token_list)
{
	t_token	*current_token;

	current_token = token_list;
	if (current_token == NULL)
		return (NULL);
	while (current_token->next != NULL)
		current_token = current_token->next;
	return (current_token);
}

void	add_token_to_end(t_token **lst, t_token *new_token)
{
	t_token	*near_last;

	if (*lst == NULL)
	{
		*lst = new_token;
		return ;
	}
	near_last = get_last_token(*lst);
	near_last->next = new_token;
	new_token->prev = near_last;
}

t_token	*create_token(char c, t_type type)
{
	t_token	*new_token;
	char	*value;

	value = (char *)malloc(2 * sizeof(char));
	if (!value)
		return (NULL);
	value[0] = c;
	value[1] = '\0';
	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = value;
	new_token->type = type;
	new_token->next = NULL;
	new_token->prev = NULL;
	return (new_token);
}

void	tokenizer(char *line, t_token **token_list)
{
	int		i;
	t_type	token_type;
	t_token	*new_token;

	i = 0;
	while (line[i] != '\0')
	{
		token_type = get_token_type(line[i]);
		new_token = create_token(line[i], token_type);
		if (!new_token)
			return ;
		add_token_to_end(token_list, new_token);
		i++;
	}
}

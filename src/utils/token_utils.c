/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:39:04 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/10/14 12:41:37 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*create_token_node(char *str, t_type type)
{
	t_token	*new_token;
	char	*value;

	value = ft_strdup(str);
	if (!value)
		return (NULL);
	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = value;
	new_token->type = type;
	new_token->next = NULL;
	new_token->prev = NULL;
	return (new_token);
}

t_token	*duplicate_token(t_token **head_token, int pipe_order)
{
	t_token	*new_head_token;
	t_token	*current_token;
	t_token	*new_token;
	int		current_pipe;

	current_token = *head_token;
	new_head_token = NULL;
	new_token = NULL;
	current_pipe = pipe_order;
	while (current_pipe > 0)
	{
		if (current_token->type == pipe_symbol)
			current_pipe--;
		current_token = current_token->next;
	}
	while (current_token != NULL && current_token->type != pipe_symbol)
	{
		new_token = create_token_node(current_token->value,
				current_token->type);
		add_token_to_end(&new_head_token, new_token);
		current_token = current_token->next;
	}
	return (new_head_token);
}

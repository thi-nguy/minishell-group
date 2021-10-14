/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:30:03 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/10/14 11:36:07 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	build_lexer(t_token **token_list)
{
	t_token	*current_token;

	current_token = *token_list;
	while (current_token)
	{
		if (current_token->type == single_quote
			|| current_token->type == double_quote)
			if (handle_quote(current_token) == -1)
				return (-1);
		if (current_token->type == variable)
		{
			handle_variable(current_token, 0);
			remove_token_node(current_token);
		}
		join_same_type_token(current_token);
		current_token = current_token->next;
	}
	return (1);
}

/*
Todo 1: handle other token types: change all to literal
Todo 2: handle variable type.
*/

int	handle_quote(t_token *quote_token)
{
	t_token	*current_token;

	current_token = quote_token->next;
	while (current_token)
	{
		if (quote_token->type == current_token->type)
		{
			remove_token_node(quote_token);
			remove_token_node(current_token);
			return (1);
		}
		if (quote_token->type == double_quote
			&& current_token->type == variable)
		{
			handle_variable(current_token, 1);
			remove_token_node(current_token);
		}
		if (quote_token->type == single_quote && current_token->type != literal)
			current_token->type = literal;
		if (current_token->type != literal && current_token->type != variable)
			current_token->type = literal;
		join_same_type_token(current_token);
		current_token = current_token->next;
	}
	printf("Error: missing quotes\n");
	return (-1);
}

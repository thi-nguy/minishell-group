/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_lexer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:48:17 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/10/14 11:52:06 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	remove_token_node(t_token *node)
{
	t_token	*prev_token;
	t_token	*next_token;

	prev_token = node->prev;
	next_token = node->next;
	free(node->value);
	node->value = NULL;
	free(node);
	node = NULL;
	if (prev_token != NULL)
		prev_token->next = next_token;
	if (next_token != NULL)
		next_token->prev = prev_token;
}

void	delete_node(t_token **head_ref, t_token *node)
{
	t_token	*temp;

	temp = *head_ref;
	if (head_ref == NULL || *head_ref == NULL)
		return ;
	if (ft_strcmp(temp->value, node->value) == 1)
	{
		*head_ref = temp->next;
		if (*head_ref != NULL)
			(*head_ref)->prev = temp;
		free(temp);
		temp = NULL;
		return ;
	}
	while (ft_strcmp(temp->value, node->value) != 1)
		temp = temp->next;
	if (temp == NULL)
		return ;
	remove_token_node(node);
}

void	join_same_type_token(t_token *current_token)
{
	t_token	*prev_token;
	t_token	*next_token;
	t_token	*new_token;
	char	*new_value;

	if (current_token->prev == NULL)
		return ;
	prev_token = current_token->prev;
	next_token = current_token->next;
	if (prev_token->type != current_token->type)
		return ;
	new_value = ft_strjoin(prev_token->value, current_token->value);
	free(prev_token->value);
	prev_token->value = new_value;
	remove_token_node(current_token);
}

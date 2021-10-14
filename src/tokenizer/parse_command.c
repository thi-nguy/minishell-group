/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:39:31 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/10/14 11:44:13 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parse_command(t_token **head_token, t_command **head_command)
{
	int	num_pipe;
	int	i;

	num_pipe = get_number_of_pipe(*head_token);
	*head_command = (t_command *)malloc(sizeof(t_command) * (num_pipe + 1));
	if (!*head_command)
		return (1);
	i = 0;
	while (i <= num_pipe)
	{
		(*head_command)[i].command_line = duplicate_token(head_token, i);
		i++;
	}
	(*head_command)[i].command_line = NULL;
	if (is_enough_command(*head_command, num_pipe) == 0)
		return (1);
	init_redirection(*head_command, num_pipe);
	if (get_redirection_status(*head_command) == 0)
		return (1);
	get_file_path(*head_command);
	get_command(*head_command);
	get_argument_array(*head_command);
	return (0);
}

void	get_argument_array(t_command *head_command)
{
	int		i;
	int		j;
	t_token	*current_token;
	t_token	*tmp;

	i = 0;
	while (head_command[i].command_line != NULL)
	{
		current_token = head_command[i].command_line;
		while (current_token)
		{
			tmp = current_token;
			if (tmp->type != literal && tmp->value)
				delete_node(&head_command[i].command_line, tmp);
			current_token = current_token->next;
		}
		i++;
	}
}

void	get_command(t_command *head_command)
{
	int		i;
	t_token	*current_token;
	char	*command;

	i = 0;
	while (head_command[i].command_line != NULL)
	{
		current_token = head_command[i].command_line;
		while (current_token && current_token->type != literal)
			current_token = current_token->next;
		if (current_token != NULL)
		{
			head_command[i].command = ft_strdup(current_token->value);
			delete_node(&head_command[i].command_line, current_token);
		}
		else
			head_command[i].command = NULL;
		i++;
	}
}

void	get_file_path(t_command *head_command)
{
	int		i;
	t_token	*current_token;
	t_type	redirect_type;

	i = 0;
	while (head_command[i].command_line != NULL)
	{
		redirect_type = head_command[i].redirect_type;
		current_token = head_command[i].command_line;
		while (current_token && current_token->type != redirect_type)
			current_token = current_token->next;
		while (current_token && current_token->type != literal)
			current_token = current_token->next;
		if (current_token != NULL)
		{
			head_command[i].file_path = ft_strdup(current_token->value);
			delete_node(&head_command[i].command_line, current_token);
		}
		else
			head_command[i].file_path = NULL;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:57:51 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/15 17:57:53 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exec_redir(t_command *command)
{
	if (command->end)
	{
		dup2(command->end, 0);
		close(command->end);
	}
	if (command->f_out)
	{
		dup2(command->f_out, 1);
		close(command->f_out);
	}
	try_exec(command->args);
	close(1);
	close(0);
	exit(0);
}

void	write_file(t_command *command_file, int fdin)
{
	int		fd;
	char	*line;

	dup2(fdin, 0);
	close(fdin);
	fd = ft_create_file(command_file->args[0], false);
	while (get_next_line(0, &line) > 0)
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
	close(0);
	exit(0);
}

void	red_left(t_command  **command, int *i)
{
	int	save_i;

	save_i = *i;
	while (command[*i + 1]
		&& (command[*i + 1]->type == CHEVRON_LL || command[*i + 1]->type == '<'))
		(*i)++;
	if (command[*i]->type == '<')
		single_left_chevron(command[save_i], command[*i]);
	else if (command[*i]->type == CHEVRON_LL)
		double_left_chevron(command[save_i], command[*i]);
}

bool	red_right(t_command **command, int *i)
{
	int	save_i;

	save_i = *i;
	while (command[*i + 1]
		&& (command[*i + 1]->type == CHEVRON_RR
			|| command[*i + 1]->type == '>'))
	{
		(*i)++;
		if (command[*i + 1]
			&& (command[*i + 1]->type == CHEVRON_RR
				|| command[*i + 1]->type == '>')
			&& (command[*i]->type == '>' || command[*i]->type == CHEVRON_RR)
			&& ft_append_file(command[*i]->args[0], true) == -1)
			return (false);
	}
	if (command[*i]->type == '>')
		single_right_chevron(command[save_i], command[*i]);
	else if (command[*i]->type == CHEVRON_RR)
		double_right_chevron(command[save_i], command[*i]);
	return (true);
}

bool	try_right(t_command **command, int *i)
{
	while (command[*i + 1]
		&& (command[*i + 1]->type == CHEVRON_RR || command[*i + 1]->type == '>'))
	{
		if (command[*i]->type == '>' || command[*i]->type == CHEVRON_RR)
		{
			if (ft_append_file(command[*i]->args[0], true) == -1)
				return (false);
		}
		(*i)++;
	}
	return (true);
}
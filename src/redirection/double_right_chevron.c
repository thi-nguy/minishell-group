/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_right_chevron.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:55:51 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/15 21:55:54 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	double_right_chevron(t_command  *command1, t_command  *command_file)
{
	int	fd1[2];
	int	fork_id;
	int	fork_id2;

	pipe(fd1);
	fork_id = fork();
	if (fork_id == 0)
	{
		close(fd1[0]);
		command1->f_out = fd1[1];
		ft_exec_redir(command1);
	}
	fork_id2 = fork();
	if (fork_id2 == 0)
	{
		close(fd1[1]);
		write_file(command_file, fd1[0]);
	}
	close(fd1[0]);
	close(fd1[1]);
	waitpid(fork_id, NULL, 0);
	waitpid(fork_id2, NULL, 0);
}

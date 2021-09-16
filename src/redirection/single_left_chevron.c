/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_left_chevron.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:17:52 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/15 17:17:53 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void read_file(t_command *command_file)
{
    int fd;
    char *line;

    fd = ft_open_file(command_file->args[0]);
    while (get_next_line(fd, &line) > 0)
    {
        write(command_file->f_out, line, ft_strlen(line));
        write(command_file->f_out, "\n", 1);
        free(line);
    }
    close(fd);
}

void single_left_chevron(t_command *command1, t_command *command_file)
{
    int fd1[2];
    int fork_id;

    pipe(fd1);
    fork_id = fork();
    if (fork_id == 0)
    {
        close(fd1[1]);
        command1->end = fd1[0];
        ft_exec_redir(command1);
    }
    else
    {
        command_file->f_out = fd1[1];
        read_file(command_file);
    }
    close(fd1[0]);
    close(fd1[1]);
    waitpid(fork_id, NULL, 0);
}
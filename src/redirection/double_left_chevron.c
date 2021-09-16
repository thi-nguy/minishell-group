/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_left_chevron.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:30:10 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/15 17:30:11 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void read_in_util(t_command *end_keyword)
{
    char    *line;

    while (get_next_line(0, &line) > 0)
    {
        if (ft_streql(line, end_keyword->args[0]))
        {
            free(line);
            break ;
        }
        write(end_keyword->f_out, line, ft_strlen(line));
        write(end_keyword->f_out, "\n", 1);
        free(line);
    }
    close(end_keyword->f_out);
    exit(0);
}

void    double_left_chevron(t_command *command1, t_command *end_keyword)
{
    int fd1[2];
    int fork_id;
    int fork_id2;

    pipe(fd1);
    fork_id2 = fork();
    if (fork_id2 == 0)
    {
        close(fd1[0]);
        end_keyword->f_out = fd1[1];
        read_in_util(end_keyword);
    }
    waitpid(fork_id2, NULL, 0);
    fork_id = fork();
    if (fork_id == 0)
    {
        close(fd1[1]);
        command1->end = fd1[0];
        ft_exec_redir(command1);
    }
    close(fd1[0]);
    close(fd1[1]);
    waitpid(fork_id, NULL, 0);
}
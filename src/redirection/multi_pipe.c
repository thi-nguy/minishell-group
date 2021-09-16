/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:18:12 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/15 14:18:15 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void child_exec_redirection(t_command *command)
{
    int     fork_id;

    fork_id = fork();
    if (fork_id == 0)
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
        //try_exec(command->args);
        close(1);
        close(0);
        exit(0);
    }
    waitpid(fork_id, NULL, 0);
}

static void close_reset_fd(t_command *command, int stdin_, int stdout_)
{
    if (command->end)
        close(command->end);
    if (command->f_out)
        close(command->f_out);
    dup2(stdin_, 0);
    dup2(stdout_, 1);
    close(stdin_);
    close(stdout_);
}

static bool open_end(t_command **command, int icommand, int *end)
{
    if (icommand == -1)
        *end = dup(0);
    else
        *end = ft_open_file(command[icommand]->args[0]);
    return (*end != -1);
}

static bool create_f_out(t_command **command, int jcommand, int *f_out)
{
    if (jcommand == -1)
        *f_out = dup(0);
    else
    {
        if (command[jcommand]->type == '>')
            *f_out = ft_create_file(command[jcommand]->args[0], false);
        else
            *f_out = ft_append_file(command[jcommand]->args[0], false);
    }
    return (*f_out != -1);
}

void    multi_pipe(t_command **command, int *i, int icommand, int jcommand)
{
    t_fd    fd;

    if (!open_end(command, icommand, &fd.end) || !create_f_out(command, jcommand, &fd.f))
        return ;
    fd.stdin_ = true;
    while (command[*i] && (fd.first || command[*i]->type == '|'))
    {
        fd.stdin_ = dup(0);
        fd.stdout_ = dup(1);
        command[*i]->end = fd.end;
        if (command[*i + 1] && command[*i + 1]->type == '|')
        {
            pipe(fd.current_pipe);
            command[*i]->f_out = fd.current_pipe[1];
            fd.end = fd.current_pipe[0];
        }
        else
            command[*i]->f_out = fd.f_out;
        child_exec_redirection(command[*i]);
        close_reset_fd(command[*i], fd.stdin_, fd.stdout_);
        fd.first = false;
        (*i)++;
    }
    if (icommand != -1 || jcommand != -1)
        *i = ft_max(icommand, jcommand);
}
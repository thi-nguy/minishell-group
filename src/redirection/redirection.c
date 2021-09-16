/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:27:23 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/14 15:27:25 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	exec_multi(t_command **command, int *save_i, int *fin, int *f_out)
{
	while (command[*save_i + 1] && command[*save_i + 1]->type == '|')
		(*save_i)++;
	if (!try_right(command, save_i))
		return (false);
	if ((command[*save_i]->type == CHEVRON_RR || command[*save_i]->type == '>'))
		*f_out = *save_i;
	while (command[*save_i + 1]
		&& (command[*save_i + 1]->type == CHEVRON_LL
			|| command[*save_i + 1]->type == '<'))
		(*save_i)++;
	if ((command[*save_i]->type == CHEVRON_LL || command[*save_i]->type == '<'))
		*fin = *save_i;
	if (*f_out == -1)
	{
		if (!try_right(command, save_i))
			return (false);
		if ((command[*save_i]->type == CHEVRON_RR || command[*save_i]->type == '>'))
			*f_out = *save_i;
	}
	return (true);
}

static bool try_multi(t_command **command, int *i)
{
    int save_i;
    int end;
    int f_out;
    int j;

    save_i = *i;
    end = -1;
    f_out = -1;
    j = 0;
    while (j++ <= 1)
        if (!exec_multi(command, &save_i, &end, &f_out))
            return (false);
    multi_pipe(command, i, end, f_out);
    return (true);
}

static bool try_simple(t_command **command, int *i)
{
    if (command[*i + 1] && command[*i + 1]->type == '|')
    {
        multi_pipe(command, i, -1, -1);
        return (false);
    }
    else if (command[*i + 1]
        && (command[*i + 1]->type == CHEVRON_RR || command[*i + 1]->type =='>'))
    {
        if (!red_right(command, i))
            return (false);
    }
    else if (command[*i + 1]
            && (command[*i + 1]->type == CHEVRON_LL || command[*i + 1]->type == '<'))
        red_left(command, i);
    return (true);
}

static bool redirection(t_command **command, int *i)
{
    if (is_simple(command, i))
    {
        if (!try_simple(command, i))
            return (false);
    }
    else if (!is_simple(command, i))
    {
        if (!try_multi(command, i))
            return (false);
    }
    return (true);

}

void    try_command(t_command **command)
{
    char    **av;
    int     i;

    i = 0;
    while (command[i])
    {
        if (command[i + 1] && command[i + 1]->type)
        {
            if (!redirection(command, &i))
                continue ;
            if (!command[i])
                break ;
        }
        else if (command[i]->str)
        {
            av = command[i]->args;
            if (count_array(av) > 0)
                update_env("_", av[count_array(av) - 1]);
            //try_exec(av);
        }
        i++;
    }
}

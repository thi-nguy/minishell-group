/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:24:04 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/15 15:24:05 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_append_file(char *str, bool should_close)
{
    int fd;

    fd = open(str, O_CREAT | O_APPEND | O_WRONLY, 0777);
    if (fd == -1)
    {
		ft_error(str, "Is a directory", 1);
		return (fd);
	}
	if (should_close)
		close(fd);
	return (fd);
}

int ft_create_file(char *str, bool should_close)
{
    int fd;

    fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0777);
    if (fd == -1)
    {
        ft_error(str, "Is a directory", 1);
        return (fd);
    }
    if (should_close)
        close(fd);
    return (fd);
}

int ft_open_file(char *str)
{
    int         fd;
    struct stat buffer;
    int         status;

    fd = open(str, &buffer);
    if (status == -1)
    {
        status = stat(str, &buffer);
		if (status == -1)
			ft_error2("cd", str, "No such file or directory", 1);
		else if (status == 0)
			ft_error("cd", "Not a directory", 1);
	}
	return (fd);
}

int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

int count_array(char **array)
{
    int i;

    i = 0;
    if (!array)
        return (0);
    while (array[i])
        i++;
    return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 02:36:29 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/05 16:07:45 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*char    *print_working_directory(t_command *cmd)
{
    t_env   *tmp;
    char    *path;

    tmp = cmd->env_head;
    while (tmp->next != NULL)
    {
        if (ft_strncmp(tmp->data, "PWD=", 4) == 0)
        {
            path = ft_strdup(tmp->data + 4);
            if (path != NULL)
                break ;
        }
        tmp = tmp->next;
    }
    return (path);
}*/

int	my_pwd(void)
{
	char	*abs_path;
	char	*res;

	abs_path = NULL;
	res = getcwd(NULL, 0);
	if (res == NULL)
	{
		printf("%s\n", strerror(errno));
		return (-1);
	}
	write(1, res, ft_strlen(res));
	write(1, "\n", 1);
	free(res);
	return (1);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:29:23 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:31:43 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//command echo
// option -n sans le saut a ligne 
int	my_echo(char **line)
{
	int	nflag;

	nflag = 0;
	line++;
	if (*line == NULL)
	{
		ft_putchar_fd('\n', 1);
		return (0);
	}
	if (ft_strncmp("-n", *line, ft_strlen(*line)) == 0)
		nflag = 1;
	line += nflag;
	while (*line != NULL)
	{
		ft_putstr_fd(*line, 1);
		if (*(line + 1) != NULL)
			ft_putchar_fd(' ', 1);
		line++;
	}
	if (!nflag)
		ft_putchar_fd('\n', 1);
	return (0);
}

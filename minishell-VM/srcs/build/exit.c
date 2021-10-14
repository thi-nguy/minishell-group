/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:29:40 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/05 02:21:52 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//check si cest un chiffre
int	check_number(char *str)
{
	if (!ft_strchr("0123456789-", *str))
		return (0);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
//commande exit sans option quit le programm
//error si non valeur numeric si plusieur valeur numeric
// touch exit controle d
int	my_exit(char **tmp)
{
	int	excode;

	while (tmp != NULL)
	{
		tmp++;
		if (*tmp == NULL)
			break ;
		if (*(tmp + 1) != NULL)
		{
			ft_putstr_fd("exit: too many arguments\n", 2);
			return (1);
		}
		if (!check_number(*tmp))
		{
			ft_putstr_fd("exit: non numeric argument\n", 2);
			return (1);
		}
		ft_putstr_fd("exit\n", 1);
		excode = ft_atoi(*tmp);
		exit(excode);
	}
	ft_putstr_fd("exit\n", 1);
	exit(0);
}

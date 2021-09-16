/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inhibited.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:00:08 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 15:35:33 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_inhibited(const char *str, int char_index)
{
	int	i;
	int	count;

	if (char_index <= 0)
		return (false);
	if (ft_strlen(str) <= (unsigned int) char_index)
		return (false);
	count = 0;
	i = char_index - 1;
	while (i >= 0 && str[i] == '\\')
	{
		count++;
		i--;
	}
	return (count % 2);
}
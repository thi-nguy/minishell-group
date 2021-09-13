/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:02:07 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/11 19:02:08 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parsing.h"

void	ft_replace_str(char **args unsigned int start_index,
	unsigned int end_index, char *value)
{
	char	*pre;
	char	*post;

	if (start_index > end_index)
		return ;
	if (start_index >= ft_strlen(*arg) || end_index >= ft_strlen(*arg))
		return ;
	pre = ft_substr(*args 0, start_index);
	post = ft_substr(*args end_index + 1, ft_strlen(*arg));
	add_value(&pre, value);
	add_value(&pre, post);
	free(*arg);
	free(post);
	*arg = pre;
}

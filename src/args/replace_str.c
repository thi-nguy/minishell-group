/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:02:07 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 15:35:44 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_replace_str(char **args, unsigned int start_index, unsigned int end_index, char *value)
{
	char	*pre;
	char	*post;

	if (start_index > end_index)
		return ;
	if (start_index >= ft_strlen(*args) || end_index >= ft_strlen(*args))
		return ;
	pre = ft_substr(*args, 0, start_index);
	post = ft_substr(*args, end_index + 1, ft_strlen(*args));
	add_value(&pre, value);
	add_value(&pre, post);
	free(*args);
	free(post);
	*args = pre;
}

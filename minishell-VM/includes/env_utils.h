/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:25:46 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/14 00:04:05 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "minishell.h"

void	print_sorted(t_list *env);
int		find_symbol(char *str, char sym);
char	*get_env_val(char *env_name, t_list *envlist);
#endif

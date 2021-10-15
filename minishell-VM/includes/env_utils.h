/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:25:46 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/15 10:58:20 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "minishell.h"

void	print_sorted(t_list *env);
int		find_symbol(char *str, char sym);
char	*get_env_val(char *env_name, t_list *envlist);

void delete_list(t_list **head_ref);

#endif

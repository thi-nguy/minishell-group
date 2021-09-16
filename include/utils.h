/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:40:55 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/16 12:40:57 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"
//parsing args

void	add_value(char **str, char *new_value);
void    ft_error(char *msg, char *error_msg, int error_code);
bool	ft_isutil(char *str);
void	ft_safe_free(void **p);
bool	ft_streql(const char *s1, const char *s2);
void	free_array(char **array);

//redirection

int     ft_append_file(char *str, bool should_close);
int     ft_create_file(char *str, bool should_close);
int     ft_open_file(char *str);
int     ft_max(int a, int b);
int     count_array(char **array);
void	write_file(t_command *command_file, int fdin);
void	ft_exec_redir(t_command *command);
bool	try_right(t_command **command, int *i);
bool	red_right(t_command **command, int *i);
void	red_left(t_command  **command, int *i);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:56:36 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 15:34:32 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define  PARSING_H

//parsing

char	**parsing(char *str);
bool	ft_valid(char *str);
void	update_struct(char c, t_parsing *parsing);
void	update_struct2(char c, t_parsing *parsing);
void    trim_args(char **args, const char *set);
bool	is_inhibited(const char *str, int char_index);
int     count_args(char *str);
void 	remove_quote(char **args);
void    remove_backslash(char **args);
void	ft_replace_str(char **args, unsigned int start_index, unsigned int end_index, char *value);
void 	split_args(char **args, char *str);
void	add_char(char **str, char c);
void	add_arg(char **args, char **tmp);
void	sub_env(char **args);
char	*ft_getenv(char *str);
void 	sub_q(char **args);
void    sub_tilde(char **args);

//command

bool 	command_valid(t_command **command);
void    add_calloc(t_command ***commandsp);
bool    double_char(char c, char next_c, char *set);
void    free_command(t_command **command);
bool 	ft_is_in_set(char c, const char *set);
t_command  **split_command(char *str);

//redirection

bool 	is_simple(t_command **command, int *j);
void   	try_command(t_command **command);
void    multi_pipe(t_command **command, int *i, int icommand, int jcommand);
void 	update_env(char *env, char *new_value);
void 	single_left_chevron(t_command *command1, t_command *command_file);
void    double_left_chevron(t_command *command1, t_command *end_keyword);
void    double_left_chevron(t_command *command1, t_command *end_keyword);
void    ft_pipe(t_command *command1, t_command *command2);
void    single_right_chevron(t_command *command1, t_command *command_file);
void	double_right_chevron(t_command  *command1, t_command  *command_file);

#endif

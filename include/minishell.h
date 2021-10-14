/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:21:13 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/10/14 11:26:53 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>

# include "../libft/libft.h"
# include "struct.h"
# include "global.h"

void		tokenizer(char *line, t_token **token_list);
t_token		*create_token(char c, t_type type);

void		add_token_to_end(t_token **lst, t_token *new_token);
t_token		*get_last_token(t_token *token_list);

void		free_all_memory(t_token **head_token);
void		free_all_memory_env(t_env **head_token);

int			build_lexer(t_token **token_list);
void		join_same_type_token(t_token *current_token);
void		remove_token_node(t_token *node);

int			handle_quote(t_token *current_token);
void		handle_variable_inside_quote(t_token *variable_token);
void		handle_variable(t_token *variable_token, int with_quote);
char		*get_variable_name(t_token *variable_token);
int			is_variable_valid(char *var_name);
char		*get_variable_value(char *var_name, int with_quote);
char		*trim_space(char *str);
char		*get_trimmed_string(char **split_result, int len);
int			get_total_len(char **split_result);
void		free_tab(char **str);

void		get_env_list(char **env);
t_env		*create_env(char *var);
void		add_env_to_end(t_env *new_env);
t_env		*get_last_env(void);
void		add_exit_code_to_env_list(int exit_code);
void		update_exit_code(int exit_code);

int			get_number_of_pipe(t_token *head_token);
t_token		*duplicate_token(t_token **head_token, int pipe_order);
int			parse_command(t_token **head_token, t_command **head_command);
int			is_enough_command(t_command *head_command, int num_pipe);
void		init_redirection(t_command *head_command, int num_pipe);
int			get_redirection_status(t_command *head_command);
void		get_file_path(t_command *head_command);
void		get_command(t_command *head_command);
void		get_argument_array(t_command *head_command);

void		delete_node(t_token **head_ref, t_token *node);
void		handle_signale_ctrl_c(int sig);
int			update_redirection_type(int len, t_type *command_type,
				t_type *token_type, t_type new_type);

// Functions outside of project.
void		print_item(t_token **token);

//command
int			my_pwd(void);
int			my_exit(char **tmp);
int			my_echo(char **line);
int			my_env(t_list *env);
int			my_unset(char **var, t_list *env);

//utils
void		exec_builtin(char *name, char **args, t_list *envlist);

#endif

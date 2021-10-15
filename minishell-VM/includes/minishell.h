/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:25:56 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/14 18:04:09 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <sys/types.h>
# include <dirent.h>
# include <signal.h>
# include <sys/wait.h>
# include <string.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <sys/stat.h>

# include "../Libft/libft.h"
# include "ast.h"
# include "env_utils.h"
# include "sig_handlers.h"
# include "struct.h"

# define QUOTES 1
# define DQUOTES 2
# define WORD 2
# define REDIR 1
# define PIPE 0
# define SEMICOL -1

char	*handle_two_left(char *str, int redir_fd, t_list *envlist);
int		check_ast(t_ast *tree);
void	exec_ast(t_ast *tree, t_list *envlist);
void	print_ast(t_ast *tree);
void	display_prompt(void);
void	free_ast(t_ast *ast);
char	*env_val_name(char *input, char *ptr, char *after_env, t_list *envlist);
char	*get_after_env(char *ptr);
void	concat_arr(char ***a, char **b);
char	**free_arr(char **arr);
char	*ft_quottrim(char *line);
char	*replace_envs(char *input, t_list *envlist, int dquot);

char	*skip_char(char *str, char sym);
void	display_prompt(void);

int		parser(char **tokenlist, t_list *env, int enter, char *argv[]);
int		my_echo(char **line);
int		my_cd(char **path, t_list *envlist);
int		my_pwd(void);
int		my_export(char **varval, t_list *env);
int		my_env(t_list *env);
int		my_unset(char **var, t_list *env);
int		my_exit(char **tmp);
char	*find_exec(t_list *env, char *filename);
char	**my_arr_realloc(char **ptr, size_t newsize);
char	*split_to_tokens(char *input, char ***arr);

char	**listtoarr(t_list *env);
char	*check_path(char *path, char *filename);
char	*find_exec(t_list *env, char *filename);
void	error_exit(void);

t_list	*converter(char **envp);

void	arraddelem(char ***array, char *string);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:59:30 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/10/14 11:21:08 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_token_type
{
	redirect_input,
	double_redirect_input,
	redirect_output,
	double_redirect_output,
	pipe_symbol,
	single_quote,
	double_quote,
	literal,
	variable,
	space,
	no_redirect
}				t_type;

typedef struct s_token
{
	char			*value;
	t_type			type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}					t_env;

typedef struct s_command
{
	t_token				*command_line;
	char				*command;
	char				*file_path;
	t_type				redirect_type;
}					t_command;

#endif

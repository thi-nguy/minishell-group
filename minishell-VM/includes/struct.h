/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:45:30 by idamoutto         #+#    #+#             */
/*   Updated: 2021/10/14 00:08:17 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

typedef struct s_tokens
{
	t_list	*env;	
	char	*ptr;
	char	*input;
	char	*crt_tkn;
	char	**tokens;
}	t_tokens;

typedef struct s_token_lst
{
	struct s_tokens_list	*next;
	char					*token;
	int						type;
}							t_token_lst;

typedef struct s_dlist {
	char			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct s_excd_sig{
	int		excode;
	int		signal;
}			t_excd_sig;

t_excd_sig	g_excd_sig;

typedef struct s_execve {
	char		*path;
	int			pid;
	char		**envarr;
	char		*relative_case;
}				t_execve;
#endif
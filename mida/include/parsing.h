/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:56:36 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/09 13:56:38 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define  PARSING_H
# include "minishell.h"
typedef struct s_parsing
{
	bool	inhibited;
	bool	single_q;
	bool	double_q;
	bool	sp;
	bool	is_inhiber;
	bool	is_simple;
	bool	is_double;
}	t_parsing;
 
 //parsing

 char	**parsing(char *str);
 bool	ft_valid(char *str);
void	update_struct(char c, t_parsing *parsing);
void	update_struct2(char c, t_parsing *parsing);

#endif
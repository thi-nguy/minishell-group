/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:16:28 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/11 18:16:30 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/parsing.h"

void    update_struct(char c, t_parsing *parsing)
{
    if (parsing->inhibited)
        parsing->inhibited = false;
    else
    {
        if (c == '\\' && !parsing->single_q)
            parsing->inhibited = true;
        if (c == '"' && !parsing->single_q)
            parsing->double_q = !parsing->double_q;
        if (c == '\'' && !parsing->double_q)
			parsing->single_q = !parsing->single_q;

    }
    
}

void	update_struct2(char c, t_parsing *parsing)
{
	parsing->single_q = parsing->is_simple;
	parsing->double_q = parsing->is_double;
	if (parsing->inhibited)
		parsing->inhibited = false;
	else if (parsing->is_inhiber)
	{
		parsing->inhibited = true;
		parsing->is_inhiber = false;
	}
	if (c == '\\' && !parsing->single_q && !parsing->inhibited)
		parsing->is_inhiber = true;
	if (c == '\'' && !parsing->double_q && !parsing->inhibited)
		parsing->is_simple = !parsing->is_simple;
	if (c == '"' && !parsing->single_q && !parsing->inhibited)
		parsing->is_double = !parsing->is_double;
}

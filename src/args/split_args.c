/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:33:05 by idamoutto         #+#    #+#             */
/*   Updated: 2021/09/13 15:35:41 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_arg(char **args, char **tmp)
{
	*args = ft_strdup(*tmp);
	ft_safe_free((void **)tmp);
}

static int	step_first(t_parsing *parsing, char str_c, char **tmp, char **args)
{
	if (!parsing->inhibited && !parsing->sp
		&& !parsing->double_q && !parsing->single_q && ft_isspace(str_c))
	{
		if (ft_isutil(*tmp))
		{
			add_arg(args, tmp);
			parsing->sp = true;
			return (1);
		}
		else
			free(tmp);
	}
	return (0);

}

static void	step_end(char str_c, char **args, char **tmp)
{
	if (str_c == 0 && ft_streql(*args, *tmp) == false)
	{
		if (ft_isutil(*tmp))
			add_arg(args, tmp);
		else
			free(*tmp);
	}
}

void	add_char(char **str, char c)
{
	char	*tmp;
	char	*tmp_c;

	tmp_c = ft_calloc(sizeof(char), 2);
	tmp_c[0] = c;
	tmp = ft_strjoin(*str, tmp_c);
	free(*str);
	free(tmp_c);
	*str = tmp;
}

void split_args(char **args, char *str)
{
    t_parsing   parsing;
    int     i;
    char    *tmp;

    tmp = 0;
    i = 0;
    parsing = (t_parsing){0};
    parsing.sp = true;
    while (*str)
    {
        update_struct2(*str, &parsing);
		if (step_first(&parsing, *str, &tmp, &args[i]))
			i++;
		if (parsing.sp && !ft_isspace(*str))
			parsing.sp = false;
		add_char(&tmp, *str);
		str++;
		step_end(*str, &args[i], &tmp);
	}
}





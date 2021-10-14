/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:58:35 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/10/14 10:59:22 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

typedef struct s_excd_sig{
	int		excode;
	int		signal;
}			t_excd_sig;

t_excd_sig	g_excd_sig;
t_env		*g_head_env;
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handlers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:26:17 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/14 00:04:08 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_HANDLERS_H
# define SIG_HANDLERS_H
# include "minishell.h"

void	proc_signal_handler(int signum);
void	signal_handler(int signo);
void	handle_sigquit(void);
//void	handle_sigint(int sig);
#endif

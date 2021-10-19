/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:30:30 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/19 11:22:27 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//ctrl+c saut a la ligne

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_excd_sig.signal = 1;
	}
	else if (signo == SIGQUIT)
	{
		exit(1);
	}
}

void	proc_signal_handler(int signum)
{
	(void)signum;
	exit(1);
	ft_putstr_fd("\nQuit\n", 2);
	exit(1);
}

void	handle_sigquit(void)
{
	ft_putstr_fd("Quit\n", 2);
	exit(131);
}

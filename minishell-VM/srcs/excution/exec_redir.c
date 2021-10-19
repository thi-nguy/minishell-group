/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:30:11 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/19 13:37:19 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//echo test2 >> text.txt rajoute a la fin du fichier le nouveau argument 

void	two_right_exec(t_ast *self)
{
	int	redir_fd;

	redir_fd = open(self->left->token, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (redir_fd < 0)
		exit(1);
	dup2(redir_fd, 1);
	close (redir_fd);
}

//echo test > ida cree un fichier txt et ecrit test si dans le meme
//fichier ecrase lancien parametre

void	one_right_exec(t_ast *self)
{
	int	redir_fd;

	redir_fd = open(self->left->token, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (redir_fd < 0)
		exit(1);
	dup2(redir_fd, 1);
	close(redir_fd);
}

// echo test < ida cree le fichier txt et ecrit le parametre et affiche le
// texte et ecrase aussi ancien parametre si le fichier sinon exit error 

void	one_left_exec(t_ast *self)
{
	int	redir_fd;

	redir_fd = open(self->left->token, O_RDONLY, S_IRWXU);
	if (redir_fd < 0)
		printf("%s:\n", strerror(errno));
	dup2(redir_fd, 0);
	close (redir_fd);
}

//cree un fichier herdoc par ex : << FIN et ecrit son text et une fois 
//terminer ecrit FIN arret du herdoc et creation dun fichier herdoc
// lors de lentrre de plusieur argument retour a la ligne do u le readline 
// cat << ida "mon nom est $USER" arret = ida affiche mon nom est idamouttou
// echo << ida $USER ida affiche idamouttou dasn herdoc
//handle two pour ex "cat" << ida
//env ?= << s ecrit le text puis ecrire s pour arret affiche la liste de
//env et ecrit le text dans le heredoc

void	two_left_exec(t_ast *self, t_list *envlist)
{
	int		redir_fd;
	char	*str;

	(void)envlist;
	redir_fd = open("heredoc", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (redir_fd < 0)
		exit(1);
	str = 0;
	while (1)
	{
		str = readline("heredoc>");
		if (ft_strcmp(str, self->left->token) == 0)
			break ;
		handle_two_left(str, redir_fd, envlist);
	}
	free(str);
	close(redir_fd);
	dup2(redir_fd, 0);
	close (redir_fd);
}

//appel des differente redirection 

void	redir_exec(t_ast	*self, t_list *envlist)
{
	if (ft_strcmp(self->token, ">") == 0)
		one_right_exec(self);
	else if (ft_strcmp(self->token, "<") == 0)
		one_left_exec(self);
	else if (ft_strcmp(self->token, ">>") == 0)
		two_right_exec(self);
	else if (ft_strcmp(self->token, "<<") == 0)
		two_left_exec(self, envlist);
	if (self->right)
		self->right->exec(self->right, envlist);
}

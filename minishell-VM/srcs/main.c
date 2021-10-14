/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:31:04 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/14 00:04:27 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//check les quote impair pair sort une error
int	check_quotes(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\"')
			str = ft_strchr(str + 1, '\"');
		if (!str)
			return (0);
		if (*str == '\'')
			str = ft_strchr(str + 1, '\'');
		if (!str)
			return (0);
		str++;
	}
	return (1);
}

void	display_prompt(void)
{
	ft_putstr_fd("minishell$ ", 2);
}

char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
	return (NULL);
}
//appel exit
//appel parsing
void	main_cycle(char *str, char **temp, t_list *envlist, t_ast *ast)
{
	while (1) //toujours vrai
	{
		str = readline("minishell$ "); //affiche minishell$
		if (!str)
			my_exit(NULL); //command exit ferme la commande utilisation de **tmp (build)
		if (ft_strlen(str) > 0)
			add_history(str);//Ajoute line au tampon d’historique, comme si c’était la dernière ligne saisie. Cela appelle la fonction add_history() readline
		else
			continue ;
		if (!check_quotes(str)) //check quote 
		{
			printf("synthax error quote not closed\n");//affiche error quote
			rl_replace_line("", 0);//sort une nouvelle ligne de commande 
			rl_redisplay(); //Modifiez ce qui est affiché à l'écran pour refléter le contenu actuel de rl_line_buffer
			continue ;
		}
		str = replace_envs(str, envlist, 0); //retour un input check les paramettre apres la command env si double quote ><?$= (parsing)
		str = split_to_tokens(str, &temp); //utilisation token check les malloc et check les command permission et les directory
		if (temp == NULL)
			continue ;
		ast = generate_ast(temp);//initialisation de ast creation du noeud redirection excution pipe execution et le reste des commande ajout de noeud pour la redirection avec le pipe
		exec_ast(ast, envlist);//excution de ast check command , pipe et redirection pour file descriptor
		free_ast(ast); //free ast
		temp = free_arr(temp); //free array
	}
}

int	main(int argc, char const *argv[], char const *envp[])
{
	char	*str;
	char	**temp;
	t_list	*envlist;
	t_ast	*ast;

	(void) argv;
	(void)argc;
	(void)ast;
	g_excd_sig.signal = 0; //(variable globale pour signal)
	temp = NULL;
	str = NULL;
	ast = NULL;
	signal(SIGQUIT, SIG_IGN); // (interruption clavier avec sauvegarde de l’image mémoire dans le fichier de nom core Ctrl \) SIG_IGN SIGNAL IGNORE;
	signal(SIGINT, signal_handler); // saut a la ligne ctrl+c fonction handler pour mettre a blanc une nouvelle ligne
	envlist = converter((char **)envp);//creation du 1er noeud et ajout de noeud a arriere 
	main_cycle(str, temp, envlist, ast);//start minishell
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:27:09 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/10/14 11:29:33 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **ev)
{
	int					exit_code;
	char				*line;
	t_token				*head_token;
	t_command			*head_command;
	struct sigaction	action;

	action.sa_handler = handle_signale_ctrl_c;
	get_env_list(ev);
	head_token = NULL;
	line = NULL;
	line = readline("minishell > ");
	exit_code = 0;
	add_exit_code_to_env_list(exit_code);
	while (1)
	{
		sigaction(SIGINT, &action, NULL);
		if (line == NULL)
			return (0);
		update_exit_code(exit_code);
		add_history(line);
		tokenizer(line, &head_token);
		if (build_lexer(&head_token) == -1)
			exit_code = 1;
		exit_code = parse_command(&head_token, &head_command);
		//if (exit_code == 0)
			//exit_code = execute_commands(&head_command, ev);
		free_all_memory(&head_token);
		head_token = NULL;
		line = readline("minishell > ");
	}
	return (0);
}

//int main(int ac, char **av, char **ev)
//{
//	t_token		*head_token;
//	t_token		*current_token;
//	t_command	*head_command;

//	char *line = "echo hehe hihi haha >> abc | pwd | cd .. << lmn";
//	int		exit_code;

//	exit_code = 0;
//	get_env_list(ev);
//	add_exit_code_to_env_list(exit_code);
//	head_token = NULL;
//	tokenizer(line, &head_token);
//	if (build_lexer(&head_token) == -1)
//	{
//		printf("Error\n");
//		return (0);
//	}
//	// print_item(&head_token);
//	int num_pipe = get_number_of_pipe(head_token);
//	exit_code = parse_command(&head_token, &head_command);
//	printf("pipe: %d\n", num_pipe);
//	int i = 0;
//	while (i <= num_pipe)
//	{
//		printf("\nCommand number: %d\n", i);
//		printf("Type de direction: %d\n", head_command[i].redirect_type);
//		printf("File path: %s\n", head_command[i].file_path);
//		printf("command: %s\n", head_command[i].command);
//		printf("Command argument: \n");
//		print_item(&head_command[i].command_line);
//		i++;
//	}
//	free_all_memory(&head_token);
//	head_token = NULL;

//	return (0);
//}

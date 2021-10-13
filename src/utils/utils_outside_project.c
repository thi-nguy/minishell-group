#include "../../include/minishell.h"

//int	main(int ac, char **av, char **ev)
//{
//	char	*line;
//	t_token	*head_token;
//	int		exit_code;
//	t_command *head_command;
//	struct sigaction action;

//	action.sa_handler = handle_signale_ctrl_c;

//	get_env_list(ev);
//	head_token = NULL;
//	line = NULL;
//	line = readline("minishell > ");
//	exit_code = 0;
//	add_exit_code_to_env_list(exit_code);
//	//TODO 1: handle signal: Ctr C, Ctr "\"
//	while (1)
//	{
//		// * for debug Ctr C D /
//		// printf("line is: |%s|\n", line);
//		// signal(SIGINT, &handle_signale_ctrl_c);
//		// line = readline("minishell > ");

//		sigaction(SIGINT, &action, NULL);
//		if (line == NULL)
//			return (0);
//		//signal(SIGQUIT, SIG_IGN);
//		update_exit_code(exit_code);
//		add_history(line);
//		// TODO 2: tokenizer inputs, handle Ctr D
//		tokenizer(line, &head_token);
//		// TODO 3: Concatenate same type tokens
//		if (build_lexer(&head_token) == -1)
//			exit_code = 1;

//		// * for debug build_lexer
//		//t_token		*current_token;
//		//current_token = head_token;
//		//while (current_token)
//		//{
//		//	printf("Data node: |%s| \t Type of data: |%d|\n", current_token->value, current_token->type);
//		//	current_token = current_token->next;
//		//}
//		// TODO 4: Check validity of command line / get linked list of command
//		exit_code = parse_command(&head_token, &head_command);
//		// * for debug parse_command
//		 int num_pipe = get_number_of_pipe(head_token);
//		 int i = 0;
//		 while (i <= num_pipe)
//		 {
//		 	printf("\nCommand number: %d\n", i);
//		 	printf("Type de direction: %d\n", head_command[i].redirect_type);
//		 	printf("File path: %s\n", head_command[i].file_path);
//		 	printf("command: %s\n", head_command[i].command);
//		 	printf("Command argument: \n");
//		 	print_item(&head_command[i].command_line);
//		 	i++;
//		 }
//		if (exit_code == 0)
//			// TODO 5: execute commands
//			//exit_code = execute_commands(&head_command);
//		free_all_memory(&head_token);
//		head_token = NULL;
//		line = readline("minishell > ");
//	}

////// * For debug
// 	// t_token		*head_token;
// 	// t_token		*current_token;
//	// t_command	*head_command;
// 	// char *line = "echo hi >> file";
//	// int		exit_code;

//	// exit_code = 0;
// 	// get_env_list(ev);
//	// add_exit_code_to_env_list(exit_code);
//	// head_token = NULL;
// 	// tokenizer(line, &head_token);
// 	// if (build_lexer(&head_token) == -1)
// 	// {
// 	// 	printf("Error\n");
// 	// 	return (0);
// 	// }
//	// // print_item(&head_token);
//	// exit_code = parse_command(&head_token, &head_command);
//	// int num_pipe = get_number_of_pipe(head_token);
//	// int i = 0;
//	// while (i <= num_pipe)
//	// {
//	// 	printf("\nCommand number: %d\n", i);
//	// 	printf("Type de direction: %d\n", head_command[i].redirect_type);
//	// 	printf("File path: %s\n", head_command[i].file_path);
//	// 	printf("command: %s\n", head_command[i].command);
//	// 	printf("Command argument: \n");
//	// 	print_item(&head_command[i].command_line);
//	// 	i++;
//	// }
//	//free_all_memory(&head_token);

//	// *for debug free memory
// 	// head_token = NULL;
// 	// tokenizer(line2, &head_token);
// 	// current_token = head_token;
// 	// while (current_token)
// 	// {
// 	// 	printf("Data node: |%s| - Type of data: |%d|\n", current_token->value, current_token->type);
// 	// 	current_token = current_token->next;
// 	// }
// 	// free_all_memory(&head_token);
// 	// head_token = NULL;

//// * For debug environment list
//	//t_env		*current_env;
//	//int		exit_code = 0;

//	//get_env_list(ev);
//	//add_exit_code_to_env_list(exit_code);
//	//current_env = g_head_env;
//	//while (current_env)
//	//{
//	//	printf("Name: |%s| \t\t Value : |%s|\n", current_env->name, current_env->value);
//	//	current_env = current_env->next;
//	//}
//	//free_all_memory_env(&g_head_env);

//// * For debug trim_space
//	//char *line = "   xy   thi-nguy    z   ";
//	//char *result;

//	//result = trim_space(line);
//	//printf("New result: |%s|\n", result);

//	return (0);
//}


void    print_item(t_token **head_token)
{
    t_token     *current_token;

    current_token = *head_token;
	while (current_token)
	{
		printf("Data node: |%s| - Type of data: |%d|\n", current_token->value, current_token->type);
		current_token = current_token->next;
	}
}



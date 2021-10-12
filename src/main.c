#include "../include/minishell.h"

void	add_exit_code_to_env_list(int exit_code)
{
	t_env		*new_env;

	new_env = (t_env *)malloc(sizeof(t_env));
    if (!new_env)
        return ;
	new_env->name = ft_strdup("EXIT_CODE");
    new_env->value = ft_itoa(exit_code);
    new_env->next = NULL;
    new_env->prev = NULL;
	add_env_to_end(new_env);
}

void	update_exit_code(int exit_code)
{
    t_env   *current_env;

    current_env = g_head_env;
    while (current_env)
    {
        if (ft_strcmp("EXIT_CODE", current_env->name) == 1)
        {
			current_env->value = ft_itoa(exit_code);
			return ;
        }
        current_env = current_env->next;
    }
}


void	handle_signale_ctrl_c(int sig)
{
	// Todo: free memory?
	printf("\nminishell > ");
	(void)sig;
}

int	main(int ac, char **av, char **ev)
{
	char	*line;
	t_token	*head_token;
	int		exit_code;
	t_command *head_command;

	get_env_list(ev);
	head_token = NULL;
	line = NULL;
	line = readline("minishell > ");
	exit_code = 0;
	add_exit_code_to_env_list(exit_code);
	//TODO 1: handle signal: Ctr C, Ctr "\"
	while (1)
	{
		// * for debug Ctr C D /
		// printf("line is: |%s|\n", line);
		// signal(SIGINT, &handle_signale_ctrl_c);
		// line = readline("minishell > ");

		signal(SIGINT, &handle_signale_ctrl_c);
		if (line == NULL)
			return (0);
		//signal(SIGQUIT, SIG_IGN);
		update_exit_code(exit_code);
		add_history(line);
		// TODO 2: tokenizer inputs, handle Ctr D
		tokenizer(line, &head_token);
		// TODO 3: Concatenate same type tokens
		if (build_lexer(&head_token) == -1)
			exit_code = 1;

		// * for debug build_lexer
		//t_token		*current_token;
		//current_token = head_token;
		//while (current_token)
		//{
		//	printf("Data node: |%s| \t Type of data: |%d|\n", current_token->value, current_token->type);
		//	current_token = current_token->next;
		//}
		// TODO 4: Check validity of command line / get linked list of command
		exit_code = parse_command(&head_token, &head_command);
		// * for debug parse_command
		// int num_pipe = get_number_of_pipe(head_token);
		// int i = 0;
		// while (i <= num_pipe)
		// {
		// 	printf("\nCommand number: %d\n", i);
		// 	printf("Type de direction: %d\n", head_command[i].redirect_type);
		// 	printf("File path: %s\n", head_command[i].file_path);
		// 	printf("command: %s\n", head_command[i].command);
		// 	printf("Command argument: \n");
		// 	print_item(&head_command[i].command_line);
		// 	i++;
		// }
		if (exit_code == 0)
			// TODO 5: execute commands
			//exit_code = execute_commands(&head_command);
		free_all_memory(&head_token);
		head_token = NULL;
		line = readline("minishell > ");
	}

//// * For debug
 	// t_token		*head_token;
 	// t_token		*current_token;
	// t_command	*head_command;
 	// char *line = "echo \"haha \" > file | pwd | cd ..";
	// int		exit_code;

	// exit_code = 0;
 	// get_env_list(ev);
	// add_exit_code_to_env_list(exit_code);
	// head_token = NULL;
 	// tokenizer(line, &head_token);
 	// if (build_lexer(&head_token) == -1)
 	// {
 	// 	printf("Error\n");
 	// 	return (0);
 	// }
	// // print_item(&head_token);
	// exit_code = parse_command(&head_token, &head_command);
	// int num_pipe = get_number_of_pipe(head_token);
	// int i = 0;
	// while (i <= num_pipe)
	// {
	// 	printf("\nCommand number: %d\n", i);
	// 	printf("Type de direction: %d\n", head_command[i].redirect_type);
	// 	printf("File path: %s\n", head_command[i].file_path);
	// 	printf("command: %s\n", head_command[i].command);
	// 	printf("Command argument: \n");
	// 	print_item(&head_command[i].command_line);
	// 	i++;
	// }
	//free_all_memory(&head_token);

	// *for debug free memory
 	// head_token = NULL;
 	// tokenizer(line2, &head_token);
 	// current_token = head_token;
 	// while (current_token)
 	// {
 	// 	printf("Data node: |%s| - Type of data: |%d|\n", current_token->value, current_token->type);
 	// 	current_token = current_token->next;
 	// }
 	// free_all_memory(&head_token);
 	// head_token = NULL;

// * For debug environment list
	//t_env		*current_env;
	//int		exit_code = 0;

	//get_env_list(ev);
	//add_exit_code_to_env_list(exit_code);
	//current_env = g_head_env;
	//while (current_env)
	//{
	//	printf("Name: |%s| \t\t Value : |%s|\n", current_env->name, current_env->value);
	//	current_env = current_env->next;
	//}
	//free_all_memory_env(&g_head_env);

// * For debug trim_space
	//char *line = "   xy   thi-nguy    z   ";
	//char *result;

	//result = trim_space(line);
	//printf("New result: |%s|\n", result);

	return (0);
}

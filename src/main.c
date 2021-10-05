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

int	main(int ac, char **av, char **ev)
{
	char	*line;
	t_token	*head_token;
	int		exit_code;

	get_env_list(ev);
	head_token = NULL;
	line = NULL;
	line = readline("minishell > ");
	exit_code = 0;
	//TODO 1: handle signal: Ctr C, Ctr "\"
	while (1)
	{
		add_exit_code_to_env_list(exit_code);
	 	add_history(line);
	 	// TODO 2: tokenizer inputs, handle Ctr D
	 	tokenizer(line, &head_token);
	 	// TODO 3: Concatenate same type tokens
	 	if (build_lexer(&head_token) == -1)
	 	{
	 		exit_code = 1;
			printf("Error\n");
	 		return (0);
	 	}
	 	t_token		*current_token;
	 	current_token = head_token;
	 	while (current_token)
	 	{
	 		printf("Data node: |%s| \t Type of data: |%d|\n", current_token->value, current_token->type);
	 		current_token = current_token->next;
	 	}
	 	// TODO 4: Check validity of command line /
	 	// parse();
	 	// TODO 5: execute commands
	 	// exit_code = execute_commands();
	 	free_all_memory(&head_token);
	 	head_token = NULL;
	 	line = readline("minishell > ");
	}

//// * For debug
 	//t_token		*head_token;
 	//t_token		*current_token;
 	//char *line = "echo \"hehe  $?\"";
	//int		exit_code;

	//exit_code = 0;
 	//get_env_list(ev);
	//add_exit_code_to_env_list(exit_code);
	//head_token = NULL;
 	//tokenizer(line, &head_token);
 	//if (build_lexer(&head_token) == -1)
 	//{
 	//	printf("Error\n");
 	//	return (0);
 	//}
 	//current_token = head_token;
	//while (current_token)
	//{
	//	printf("Data node: |%s| - Type of data: |%d|\n", current_token->value, current_token->type);
	//	current_token = current_token->next;
	//}
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

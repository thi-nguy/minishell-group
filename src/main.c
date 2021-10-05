#include "../include/minishell.h"


int	main(int ac, char **av, char **ev)
{
	char	*line;
	t_token	*head_token;

	get_env_list(ev);
	head_token = NULL;
	line = NULL;
	line = readline("minishell > ");
	// TODO 1: handle signal: Ctr C, Ctr "\"
	while (1)
	{
	 	add_history(line);
	 	// TODO 2: tokenizer inputs, handle Ctr D
	 	tokenizer(line, &head_token);
	 	// TODO 3: Concatenate same type tokens
	 	if (build_lexer(&head_token) == -1)
	 	{
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
	 	// TODO 4: Parse, Build AST /
	 	// parse();
	 	// TODO 5: execute commands in AST
	 	// execute_syntax_tree();

	 	free_all_memory(&head_token);
	 	head_token = NULL;
	 	line = readline("minishell > ");
	}

//// * For debug
// 	t_token		*head_token;
// 	t_token		*current_token;
// 	char *line = "echo $var xyz";
//  char *line2 = "x|z";

// 	head_token = NULL;

// 	tokenizer(line, &head_token);
// 	if (build_lexer(&head_token) == -1)
// 	{
// 		printf("Error\n");
// 		return (0);
// 	}
// 	current_token = head_token;
//	while (current_token)
//	{
//		printf("Data node: |%s| - Type of data: |%d|\n", current_token->value, current_token->type);
//		current_token = current_token->next;
//	}
//	free_all_memory(&head_token);
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
// * For debug environment list
	//t_env		*current_env;

	//get_env_list(ev);
	//current_env = g_head_env;
	//while (current_env)
	//{
	//	printf("Name: |%s| \tValue : |%s|\n", current_env->name, current_env->value);
	//	current_env = current_env->next;
	//}
	//free_all_memory_env(&g_head_env);
	return (0);
}

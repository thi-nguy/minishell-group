#include "../include/minishell.h"

int	main(int ac, char **av, char **ev)
{
     char	*line;
	 t_token	*head_token;


	 line = NULL;
	 line = readline("minishell > ");
	 ft_bzero(&g_info, sizeof(g_info));
	// TODO 1: handle signal: Ctr C, Ctr "\"
	 while (1)
	 {
	 	add_history(line);
	 	// TODO 2: tokenizer inputs, handle Ctr D
	 	tokenizer(line, head_token);
		// !debug
		t_token		*current_token;
		current_token = head_token;
		while (current_token)
		{
			printf("Data node: |%s| - Type of data: |%d|\n", current_token->value, current_token->type);
			current_token = current_token->next;
		}

	 	//// TODO 3: Concatenate same type tokens
		//build_lexer();
	 	//// TODO 4: Parse, Build AST /
		// parse();
	 	//// TODO 5: execute commands in AST
		// execute_syntax_tree();

	 	//free_all_memory();
	 	line = readline("minishell > ");
	 }

	// For debug
	//ft_bzero(&g_info, sizeof(g_info));
	//char *line1 = "hello world";
	//tokenizer(line1);
	//concat_same_type_token();
	//while (g_info.list_input)
	//{
	//	print_item(g_info.list_input->content);
	//	g_info.list_input = g_info.list_input->next;
	//}
	//free_all_memory();

	return (g_info.return_value);
}

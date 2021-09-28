#include "minishell.h"

int	main(int ac, char **av, char **ev)
{
     char	*line;
	 t_token	*head_token;

		head_token = NULL;

	 line = NULL;
	 line = readline("minishell > ");
	// TODO 1: handle signal: Ctr C, Ctr "\"
	 while (1)
	 {
	 	add_history(line);
	 	// TODO 2: tokenizer inputs, handle Ctr D
	 	tokenizer(line, &head_token);
		t_token		*current_token;
		current_token = head_token;
		while (current_token)
		{
			printf("Data node: |%s| - Type of data: |%d|\n", current_token->value, current_token->type);
			current_token = current_token->next;
		}
	 	// TODO 3: Concatenate same type tokens
		//build_lexer();
	 	// TODO 4: Parse, Build AST /
		// parse();
	 	// TODO 5: execute commands in AST
		// execute_syntax_tree();

	 	free_all_memory(&head_token);
		head_token = NULL;
	 	line = readline("minishell > ");
	 }

	// * For debug
	// t_token		*head_token;
	// t_token		*current_token;
	// char *line = "a b";
	// char *line2 = "x|z";

	// head_token = NULL;
	
	// tokenizer(line, &head_token);
	// current_token = head_token;
	// while (current_token)
	// {
	// 	printf("Data node: |%s| - Type of data: |%d|\n", current_token->value, current_token->type);
	// 	current_token = current_token->next;
	// }
	// free_all_memory(&head_token);
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
	return (0);
}

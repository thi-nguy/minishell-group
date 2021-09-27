#include "../include/minishell.h"

int	main(int ac, char **av, char **ev)
{
    // char	*line;

	// line = NULL;
	// line = readline("minishell > ");
	// ft_bzero(&g_info, sizeof(g_info));
	// while (1)
	// {
	// 	add_history(line);
	// 	// TODO 1: handle signal: Ctr C, Ctr \

	// 	// TODO 2: tokenizer inputs, handle Ctr D
	// 	tokenizer(line);

	// 	// TODO 3: Concatenate same type tokens
	//	concat_same_type_token();

	// 	// TODO 4: Build AST /
	// 	// TODO 5: execute commands in AST

	// 	free_all_memory();
	// 	line = readline("minishell > ");
	// }

	// For debug
	ft_bzero(&g_info, sizeof(g_info));
	char *line1 = "hello world";
	tokenizer(line1);
	concat_same_type_token();
	while (g_info.list_input)
	{
		print_item(g_info.list_input->content);
		g_info.list_input = g_info.list_input->next;
	}
	free_all_memory();

	return (g_info.return_value);
}

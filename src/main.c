#include "../include/minishell.h"

int	main(int ac, char **av, char **ev)
{
     char	*line;

	 line = NULL;
	 line = readline("minishell > ");
	 ft_bzero(&g_info, sizeof(g_info));
	 while (1)
	 {
	 	add_history(line);
	 	// TODO 1: handle signal: Ctr C, Ctr \
	 	// TODO 2: tokenizer inputs, handle Ctr D
	 	tokenizer(line);
	 	// TODO 3: Parse
	 	// TODO 4: Build AST /
	 	// TODO 5: execute commands in AST

	 	free_all_memory();
	 	line = readline("minishell > ");
	 }

	// For debug
	//ft_bzero(&g_info, sizeof(g_info));
	//char *line1 = "a b c";
	//tokenizer(line1);
	//free_all_memory();
	//char *line2 = "xyz";
	//tokenizer(line2);
	//free_all_memory();

	return (g_info.return_value);
}

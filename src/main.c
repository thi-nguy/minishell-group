#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
    char	*line;
	t_command	*command;

	line = NULL;
	line = readline("minishell > ");
	while (ft_strcmp(line, "exit") == 0)
	{
		// Todo: launch minishell
		printf("Ok\n");
		free(line);
		line = readline("minishell > ");
	}
	return (0);
}

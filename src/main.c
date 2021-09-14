#include "minishell.h"

int	main(int ac, char **av, char **ev)
{
    char	*line;
	t_command	command;
	int	total_env_var;

	total_env_var = count_env_var(ev);
	parse_env(&command, ev, total_env_var);
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

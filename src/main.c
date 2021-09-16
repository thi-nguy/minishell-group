#include "minishell.h"

int	main(int ac, char **av, char **ev)
{
    char	*line;
	t_command	command;
	int	total_env_var;
	char	*path;

	total_env_var = count_env_var(ev);
	parse_env(&command, ev, total_env_var);
	line = NULL;
	line = readline("minishell > ");
	while (ft_strcmp(line, "exit") == 0)
	{
		// Todo: launch minishell
		add_history(line);
		if (ft_strcmp(line, "pwd") != 0)
		{
			path = print_working_directory(&command);
			printf("%s\n", path);
			free(path);
			path = NULL;
		}
		else if (ft_strcmp(line, "env") != 0)
			print_env_var(&command);
		else
			printf("Ok\n");
		free(line);
		line = readline("minishell > ");
	}
	free_memory(command.env_head);
	return (0);
}

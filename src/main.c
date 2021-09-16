#include "../include/minishell.h"

static bool	is_comment(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '#')
		return (true);
	return (false);
}

static bool	run_sh(int ac, char **av)
{
	t_command		**redir;
	char			*line;
	int				fd;

	if (ac > 2)
		return (true);
	else if (ac == 2 && is_suffix(av[1], ".sh"))
	{
		fd = open(av[1], O_RDWR);
		if (fd == -1)
			return (true);
		while (get_next_line(fd, &line) > 0)
		{
			if (!is_comment(line))
			{
				redir = split_command(line);
				try_command(redir);
			}
			free(line);
		}
		close(fd);
		printf("\n\n");
		return (true);
	}
	return (false);
}

static bool	ft_tester(int ac, char **av)
{
	t_command	**redir;

	if (ac >= 3 && !ft_strncmp(av[1], "-c", 3))
	{
		redir = split_command(av[2]);
		try_command(redir);
		return (true);
	}
	return (false);
}

int	main(int ac, char **av, char **ev)
{
    char	*line;
	t_command	command;
	int	total_env_var;
	char	*path;
	char	**shell_var;

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
		else if (is_shell_var(line) == true)
			parse_shell_var(&command, line);
		else
			printf("Ok\n");
		free(line);
		line = readline("minishell > ");
	}
	free_memory(command.env_head);
	return (0);
}

// int main(int ac, char **av, char **ev)
// {
//	 int i;

//	 i = -1;
//	 g_global.env = ft_calloc(sizeof(char *), count_array(ev) + 1);
//	 while (ev[++i])
//		g_global.env[i] = ft_strdup(ev[i]);
//	//signal
//	//signal
//	if (ft_tester(ac, av) || run_sh(ac, av))
//		return (0);
//	//minishell();
//	return (0);
// }



#include "../include/minishell.h"

int	main(int ac, char **av, char **ev)
{
	int					exit_code;
	char				*line;
	t_token				*head_token;
	t_command 			*head_command;
	struct sigaction 	action;

	action.sa_handler = handle_signale_ctrl_c;
	get_env_list(ev);
	head_token = NULL;
	line = NULL;
	line = readline("minishell > ");
	exit_code = 0;
	add_exit_code_to_env_list(exit_code);
	while (1)
	{
		sigaction(SIGINT, &action, NULL);
		if (line == NULL)
			return (0);
		update_exit_code(exit_code);
		add_history(line);
		tokenizer(line, &head_token);
		if (build_lexer(&head_token) == -1)
			exit_code = 1;
		exit_code = parse_command(&head_token, &head_command);
		if (exit_code == 0)
			//exit_code = execute_commands(&head_command, ev);
		free_all_memory(&head_token);
		head_token = NULL;
		line = readline("minishell > ");
	}
	return (0);
}

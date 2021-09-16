#include "../../include/minishell.h"

t_env	*add_to_empty(t_env *head, char *data)
{
	t_env	*tmp;

	tmp = (t_env *)malloc(sizeof(t_env) * 1);
	if (!tmp)
		return (NULL);
	tmp->data = ft_strdup(data);
	tmp->next = NULL;
	tmp->prev = NULL;
	head = tmp;
	return (head);
}

t_env	*insert_at_beginning(t_env *head, char *data)
{
	t_env	*tmp;

	tmp = (t_env *)malloc(sizeof(t_env) * 1);
	if (!tmp)
		return (NULL);
	tmp->data = ft_strdup(data);
	tmp->next = head;
	tmp->prev = NULL;
	head->prev = tmp;
	head = tmp;
	return (head);
}

void	parse_env(t_command *command, char **env, int size)
{
    int     i;

	i = size - 1;
	command->env_head = add_to_empty(command->env_head, env[i]);
	command->env_end = command->env_head;
    i--;
	while (i >= 0)
	{
		command->env_head = insert_at_beginning(command->env_head, env[i]);
		i--;
	}
}


int     count_env_var(char **env)
{
    int i;

    i = 0;
    while (env[i] != NULL)
        i++;
    return (i);
}


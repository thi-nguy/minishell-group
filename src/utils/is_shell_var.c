#include "minishell.h"

bool    is_shell_var(char *line)
{
    int     i;

    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '=')
            return (true);
        i++;
    }
    return (false);
}

void    parse_shell_var(t_command *command, char *line)
{
    char    **split_result;

    split_result = ft_split(line, '=');
    if (is_syntax_valid(split_result) == false)
        return ;
    if (command->shell_var_head == NULL)
    {
        command->shell_var_head = add_to_empty_var_list(command->shell_var_head, split_result);
        command->shell_var_end = command->shell_var_head;
    }
    else
        update_var(command->shell_var_head, split_result);
}

void        update_var(t_shell_var *head, char **shell_var)
{
    t_shell_var     *current;

    current = head;
    while (current != NULL)
    {
        if (ft_strcmp(current->var_name, shell_var[0]) != 0)
        {
            printf("ok\n");
            //todo: change_var_value
        }
        current = current->next;
    }
    //Todo: insert_at_tail()

}

t_shell_var     *add_to_empty_var_list(t_shell_var *head, char **shell_var)
{
    t_shell_var *tmp;

    tmp = (t_shell_var *)malloc(sizeof(t_shell_var) * 1);
	if (!tmp)
		return (NULL);
	tmp->var_name = ft_strdup(shell_var[0]);
    tmp->value = ft_strdup(shell_var[1]);
	tmp->next = NULL;
	tmp->prev = NULL;
	head = tmp;
	return (head);
}


bool    is_syntax_valid(char **table)
{
    int     len_var_name;
    int     len_var_value;

    len_var_name = ft_strlen(table[0]);
    len_var_value = ft_strlen(table[1]);
    if (table[0][len_var_name - 1] == ' ')
        return (false);
    if (table[1][0] != '"' || table[1][len_var_value - 1] != '"')
        return (false);
    return (true);
}

#include "minishell.h"

void	free_memory(t_env *env_list)
{
	while (env_list->next != NULL)
	{
        env_list = env_list->next;
        free(env_list->prev->data);
        env_list->prev->data = NULL;
        free(env_list->prev);
        env_list->prev = NULL;
	}
    free(env_list->data);
    env_list->data = NULL;
    free(env_list);
    env_list = NULL;
}
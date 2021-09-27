#include "minishell.h"

t_token_type        get_token_type(char c)
{
    if (c == '>')
        return (right_redirection);
    else if (c == '<')
        return (left_redirection);
    // else if (c == '>>')
    //     return (double_left_redirection);
    // else if (c == '<<')
    //     return (double_right_redirection);ech
    else if (c == '|')
        return (pipe_symbol);
    else if (c == '\'')
        return (single_quote);
    else if (c == '"')
        return (double_quote);
    else if (c == ' ' || c == '\t' || c == '\f' || c == '\r' || c == '\v')
        return (space);
    else if (c == '$')
        return (variable);
    else
        return (literal);
}

t_token     *create_token(char c, t_token_type type)
{
    t_token *new_token;
    char *value;

    value = (char *)malloc(2 * sizeof(char));
    if (!value)
        return (NULL);
    value[0] = c;
    value[1] = '\0';
    new_token = (t_token*)malloc(sizeof(t_token));
    if (!new_token)
        return (NULL);
    new_token->value = value;
    new_token->type = type;
    return (new_token);
}


void    tokenizer(char *line)
{
    int i;
    t_list				*new;
	t_token				*token;
	t_token_type		token_type;

    i = 0;
    while (line[i] != '\0')
    {
        token_type = get_token_type(line[i]);
        token = create_token(line[i], token_type);
        new = ft_lstnew(token);
        if (!new)
            return ;
        ft_lstadd_back(&g_info.list_input, new);
        i++;
    }
    //ft_lstiter(g_info.list_input, print_item);
}

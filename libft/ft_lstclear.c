/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:39:28 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/09/26 21:29:36 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list *lst, void (*del)(void *))
{
	t_list *element;

	if (!del)
		return ;
	while (lst)
	{
		(*del)(lst->content);
		element = lst;
		lst = element->next;
		free(element);
		element = NULL;
	}
	lst = NULL;
}

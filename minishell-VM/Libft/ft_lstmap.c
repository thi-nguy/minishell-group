/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:19:30 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:27:09 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (!(res))
		return (NULL);
	node = res;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew(f(lst->content));
		if (!(node->next))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		node = node->next;
		lst = lst->next;
	}
	return (res);
}

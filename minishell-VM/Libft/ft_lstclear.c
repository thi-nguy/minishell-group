/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:18:35 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:27:13 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (((*lst)->next) != NULL)
		ft_lstclear(&((*lst)->next), del);
	ft_lstdelone(*(lst), del);
	*lst = NULL;
}

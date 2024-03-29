/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:38:39 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/09/26 20:42:46 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *near_last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	near_last = ft_lstlast(*lst);
	near_last->next = new;
	new->prev = near_last;
}

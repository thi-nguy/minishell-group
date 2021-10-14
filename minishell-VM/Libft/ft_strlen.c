/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:23:10 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:43 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char	*ptr;
	int		res;

	if (s == NULL)
		return (0);
	if (!s[0])
		return (0);
	res = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		res++;
		ptr++;
	}
	return (res);
}

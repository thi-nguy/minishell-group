/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:23:41 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:38 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*res;

	res = NULL;
	ptr = (char *)s;
	while (*ptr != '\0')
	{
		if (*ptr == c)
			res = ptr;
		ptr++;
	}
	if (c == 0)
		res = ptr;
	return (res);
}

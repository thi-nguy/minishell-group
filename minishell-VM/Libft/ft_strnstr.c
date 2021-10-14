/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:23:34 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:40 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*cp_big;
	const char	*cp_little;
	size_t		n;

	cp_big = big;
	cp_little = little;
	n = len;
	if (*cp_little == '\0')
		return ((char *)cp_big);
	while (*cp_big != '\0' && n > 0)
	{
		if (ft_strncmp(little, cp_big, ft_strlen(little)) == 0
			&& n >= ft_strlen(little))
			return ((char *)cp_big);
		n--;
		cp_big++;
	}
	return (NULL);
}

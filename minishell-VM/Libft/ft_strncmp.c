/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:23:27 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:41 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1;
	unsigned char		*str2;

	if ((s1 && (s1 == s2)) || !n)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n-- && (*str1 || *str2))
	{
		if (*str1++ != *str2++)
			return (*(--str1) - *(--str2));
	}
	return (0);
}

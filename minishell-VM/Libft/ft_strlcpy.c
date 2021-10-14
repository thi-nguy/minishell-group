/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:23:03 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:45 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcpy(char const *dst, char const *src, size_t dstsize)
{
	char			*cpy_dst;
	const char		*s;
	size_t			n;

	s = src;
	cpy_dst = (char *)dst;
	n = dstsize;
	if (n != 0)
		while (--n && *s != '\0')
			*cpy_dst++ = *s++;
	if (n == 0)
	{
		if (dstsize != 0)
			*cpy_dst = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}

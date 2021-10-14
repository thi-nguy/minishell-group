/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:20:06 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:27:02 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;

	cpy_dest = (unsigned char *)dest;
	cpy_src = (unsigned char *)src;
	while (n--)
	{
		*cpy_dest = *cpy_src;
		if (*cpy_src == (unsigned char)c)
			return (cpy_dest + 1);
		cpy_dest++;
		cpy_src++;
	}
	return (NULL);
}

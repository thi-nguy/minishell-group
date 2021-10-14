/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:20:48 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:58 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;
	size_t			len;

	if (dest == NULL && src == NULL)
		return (dest);
	len = n;
	cpy_dest = (unsigned char *)dest;
	cpy_src = (unsigned char *)src;
	if (cpy_dest < cpy_src)
		while (len--)
			*cpy_dest++ = *cpy_src++;
	else
		while (len-- > 0)
			cpy_dest[len] = cpy_src[len];
	return (dest);
}

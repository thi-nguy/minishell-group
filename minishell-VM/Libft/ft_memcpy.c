/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:20:32 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:59 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;

	cpy_dest = (unsigned char *)dest;
	cpy_src = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n--)
		*cpy_dest++ = *cpy_src++;
	return (dest);
}

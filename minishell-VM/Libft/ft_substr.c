/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:23:55 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:36 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	n;

	n = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (!(ptr)
		|| !(s))
		return (NULL);
	while (n < len && start + n < ft_strlen(s))
	{
		ptr[n] = (char)s[start + n];
		++n;
	}
	ptr[n] = '\0';
	return (ptr);
}

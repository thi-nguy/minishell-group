/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:22:46 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:47 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*res;
	size_t	n;

	if ((!(s1 && s2)))
		return (NULL);
	n = 1 + ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (n));
	if (!(ptr))
		return (NULL);
	res = ptr;
	while (n-- && *s1 != '\0')
		*ptr++ = *s1++;
	while (n-- && *s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:23:47 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:37 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char s1, char const *set)
{
	char	*pt_set;

	pt_set = (char *)set;
	while (*pt_set != '\0')
	{
		if (s1 == *pt_set)
			return (1);
		pt_set++;
	}
	return (0);
}

static size_t	ft_reslen(char const *s1, char const *set)
{
	char			*pt_s1;
	static size_t	n;
	int				e;

	e = 0;
	n = ft_strlen(s1);
	pt_s1 = (char *)s1;
	while (ft_isset(*pt_s1, set) && *pt_s1 != '\0')
	{
		n--;
		pt_s1++;
	}
	while (pt_s1[e] != '\0')
		e++;
	e = e - 1;
	while (ft_isset(pt_s1[e], set) && n)
	{
		e = e - 1;
		n = n - 1;
	}
	return (n);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pt_s1;
	char	*ptr_res;
	char	*res;
	int		z;

	if (!(s1 && set))
		return (NULL);
	z = ft_reslen(s1, set);
	res = malloc(sizeof(char) * (1 + z));
	if (!(res))
		return (NULL);
	res[z] = '\0';
	pt_s1 = (char *)s1;
	ptr_res = res;
	while (ft_isset(*pt_s1, set) && *pt_s1 != '\0')
		pt_s1++;
	while (*pt_s1 != '\0' && res && z > 0)
	{
		*res++ = *pt_s1++;
		z--;
	}
	return (ptr_res);
}

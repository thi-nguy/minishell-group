/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:23:18 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:42 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned
int, char))
{
	char	*res;
	size_t	n;

	n = 0;
	if (!(s && f))
		return (NULL);
	res = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!(res))
		return (NULL);
	while (n < ft_strlen(s))
	{
		res[n] = f(n, s[n]);
		n++;
	}
	res[n] = '\0';
	return (res);
}

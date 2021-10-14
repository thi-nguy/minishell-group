/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:22:37 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:48 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const char	*cps;
	char		*res;
	char		*cp_res;

	if (s == NULL)
		return (NULL);
	cps = s;
	res = malloc((ft_strlen(s) + 1) * sizeof(const char));
	if (!(res))
		return (NULL);
	cp_res = res;
	while (*cps)
	{
		ft_memset(cp_res, *cps, 1);
		cp_res++;
		cps++;
	}
	ft_memset(cp_res, '\0', 1);
	return (res);
}

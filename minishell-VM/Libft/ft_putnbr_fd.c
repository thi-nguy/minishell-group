/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:21:44 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/04 23:26:54 by idamouttou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	res[16];
	int		i;

	i = 15;
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	write(fd, "-", n < 0);
	if (n < 0)
		n *= -1;
	while (n)
	{
		res[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	while (i + 1 < 16)
	{
		write(fd, &res[i + 1], 1);
		i++;
	}
}

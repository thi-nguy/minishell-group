/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:35:52 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/01/06 08:50:51 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 10

char	*ft_strcpy(char *dst, const char *src);
char	*join_str(char *s1, char *s2);
int		find_n(const char *str, int c);
int		get_line(char **str, char **line, int i);
int		get_next_line(int fd, char **line);

#endif

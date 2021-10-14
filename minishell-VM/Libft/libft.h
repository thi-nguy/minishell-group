/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:24:20 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/14 15:57:38 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// noeud = liste chainee sous forme de structure
// content = element donne pour chaque noeud
// next = pointeur pour stocker laddress du noeud suivant ce pointeur sert 
// de lien entre chaque noeud

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstnew(void *content);
char			*ft_strdup(const char *s);
int				ft_tolower(int c);
int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isprint(int c);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
char			*ft_itoa(int n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putnbr_fd(int n, int fd);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlcpy(char const *dst, char const *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isprint_no_equal(int c);
int				ft_isprint_no_equal(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
#endif

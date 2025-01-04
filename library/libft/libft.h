/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:36:56 by tripham           #+#    #+#             */
/*   Updated: 2024/11/16 20:21:31 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_byte;

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

void					*ft_memset(void *ptr, int value, size_t num);
void					ft_bzero(void *s, size_t len);
void					*ft_memcpy(void *des, const void *src, size_t len);
void					*ft_memmove(void *dest_str, const void *src_str,
							size_t numBytes);
void					*ft_memchr(const void *str, int c, size_t n);
void					*ft_calloc(size_t count, size_t size);
char					*ft_strdup(const char *src);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strnstr(const char *big, const char *small,
							size_t len);
char					*ft_substr(const char *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_itoa(int n);
char					**ft_split(char const *s, char c);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_putchar_fd(char c, int fd);
char					*ft_strtrim(char const *s1, char const *set);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
size_t					ft_strlen(const char *str);
size_t					ft_strlcat(char *des, const char *src,
							size_t sizeOfDes);
size_t					ft_strlcpy(char *des, const char *src, size_t size);

int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_atoi(const char *str);
int						ft_memcmp(const void *str1, const void *str2, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);

t_list					*ft_lstnew(void *content);
t_list					*ft_lstlast(t_list *lst);
int						ft_lstsize(t_list *lst);
void					ft_lstadd_front(t_list **lst, t_list *new);
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));

#endif

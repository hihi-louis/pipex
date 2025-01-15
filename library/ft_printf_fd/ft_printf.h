/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:55:09 by tripham           #+#    #+#             */
/*   Updated: 2025/01/13 20:37:40 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_putchar_fd(int fd, char c);
int	ft_putnbr_fd(int fd, int n);
int	ft_putstr_fd(int fd, char *s);
int	ft_putpointer_fd(int fd, void *p);
int	ft_puthexa_fd(int fd, unsigned int n, char c);
int	ft_putuint_fd(int fd, unsigned int n);
int	ft_printf_fd(int fd, const char *format, ...);
int	ft_putbase_fd(int fd, unsigned long nb, char *base);

#endif

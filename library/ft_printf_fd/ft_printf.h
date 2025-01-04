/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:55:09 by tripham           #+#    #+#             */
/*   Updated: 2024/11/24 19:03:12 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar_fd(int fd, char c);
int	ft_putnbr_fd(int fd, int n);
int	ft_putstr_fd(int fd, char *str);
int	ft_putpointer_fd(int fd, unsigned long long p);
int	ft_puthex_fd(int fd, unsigned long long n, const char type);
int	ft_putui_fd(int fd, unsigned int n);
int	ft_printf_fd(int fd, const char *format, ...);

#endif

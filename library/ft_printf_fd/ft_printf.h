/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:55:09 by tripham           #+#    #+#             */
/*   Updated: 2025/01/18 04:10:37 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "../libft/libft.h"

char	*ft_base_check(int baselen, int low_or_up);
char	*ft_check_format_fd(char specifier, va_list ap);
int		ft_printf_fd(int fd, const char *format, ...);
char	*ft_putnbr_base_fd(long long nbr, int baselen, int low_or_up);
char	*ft_putchar_fd(int c);
char	*ft_putpointer_fd(uintptr_t nbr, int baselen, int low_up);
char	*ft_putstr_fd(char *s);
#endif

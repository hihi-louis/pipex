/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:54:50 by tripham           #+#    #+#             */
/*   Updated: 2025/01/17 02:58:38 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static int	ft_check_format_fd(int fd, va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_fd(fd, va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_fd(fd, va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putpointer_fd(fd, va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(fd, va_arg(args, int)));
	else if (c == 'u')
		return (ft_putuint_fd(fd, va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthexa_fd(fd, va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_putchar_fd(fd, '%'));
	else
		return (-1);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list			args;
	unsigned int	len;
	int				temp;

	len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && ft_strchr("cspdiuxX%", *(str + 1)))
			temp = ft_check_format_fd(fd, args, *(str++ + 1));
		else
			temp = ft_putchar_fd(fd, *str);
		if (temp == -1)
			return (-1);
		len += temp;
		str++;
	}
	va_end(args);
	return (len);
}

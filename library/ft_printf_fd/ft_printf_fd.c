/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:54:50 by tripham           #+#    #+#             */
/*   Updated: 2025/01/04 18:10:54 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format_fd(int fd, const char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar_fd(fd, va_arg(args, int)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(fd, va_arg(args, int)));
	else if (format == 'p')
		return (ft_putpointer_fd(fd, (unsigned long long)va_arg(args, void *)));
	else if (format == 's')
		return (ft_putstr_fd(fd, va_arg(args, char *)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex_fd(fd, va_arg(args, unsigned int), format));
	else if (format == 'u')
		return (ft_putui_fd(fd, va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_putchar_fd(fd, '%'));
	else
	{
		ft_putstr_fd(fd, "Error format\n");
		return (-1);
	}
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		len;
	int		check_error;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_error = check_format_fd(fd, *format, args);
			if (check_error == -1)
			{
				return (va_end(args), -1);
			}
			len += check_error;
		}
		else
			len += ft_putchar_fd(fd, *format);
		format++;
	}
	va_end(args);
	return (len);
}

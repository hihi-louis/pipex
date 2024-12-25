/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:54:50 by tripham           #+#    #+#             */
/*   Updated: 2024/12/25 11:03:01 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int	check_format(const char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'p')
		return (ft_putpointer((unsigned long long)va_arg(args, void *)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == 'u')
		return (ft_putui(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	else
	{
		ft_putstr("Error format\n");
		return (-1);
	}
}

int	ft_printf(const char *format, ...)
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
			check_error = check_format(*format, args);
			if (check_error == -1)
			{
				return (va_end(args), -1);
			}
			len += check_error;
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}
int main()
{
	char *str = "%123";
	ft_printf("abc is 32423\n");
	#include <stdio.h>
	printf("a %%1234\n");
	return 0;
}

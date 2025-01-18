/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 03:48:51 by tripham           #+#    #+#             */
/*   Updated: 2025/01/18 04:12:39 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_format_fd(char specifier, va_list ap)
{
	char	*wrote;

	if (specifier == 'c')
		wrote = ft_putchar_fd(va_arg(ap, int));
	else if (specifier == 's')
		wrote = ft_putstr_fd(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		wrote = ft_putnbr_base_fd(va_arg(ap, int), 10, 0);
	else if (specifier == 'u')
		wrote = ft_putnbr_base_fd((unsigned int)va_arg(ap, int), 10, 0);
	else if (specifier == 'x')
		wrote = ft_putnbr_base_fd(va_arg(ap, unsigned), 16, 0);
	else if (specifier == 'X')
		wrote = ft_putnbr_base_fd(va_arg(ap, unsigned), 16, 1);
	else if (specifier == 'p')
		wrote = ft_putpointer_fd((uintptr_t)va_arg(ap, void *), 16, 0);
	else if (specifier == '%')
		wrote = ft_strdup("%");
	else
		wrote = (ft_strdup(&specifier));
	return (wrote);
}

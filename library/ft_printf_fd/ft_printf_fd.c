/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:54:50 by tripham           #+#    #+#             */
/*   Updated: 2025/01/18 04:12:26 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static void	ft_free(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

static char	*ft_formatting_fd(va_list ap, const char *format)
{
	char	*final;
	char	*str_is_not_formatting;
	char	*wrote;
	int		i;

	i = 0;
	str_is_not_formatting = ft_strdup("");
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			wrote = ft_check_format_fd(format[++i], ap);
		else
			wrote = ft_putchar_fd(format[i]);
		final = ft_strjoin(str_is_not_formatting, wrote);
		ft_free(str_is_not_formatting);
		ft_free(wrote);
		str_is_not_formatting = final;
		i++;
	}
	return (str_is_not_formatting);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	ap;
	char	*total_char;
	int		wrote;

	wrote = 0;
	va_start(ap, format);
	total_char = ft_formatting_fd(ap, format);
	va_end(ap);
	wrote = write(fd, total_char, ft_strlen(total_char));
	ft_free(total_char);
	if (wrote == -1)
		return (-1);
	return (wrote);
}

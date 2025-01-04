/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:55:03 by tripham           #+#    #+#             */
/*   Updated: 2025/01/04 18:11:03 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putchr_hex_fd(int fd, unsigned long long n, const char type)
{
	if (n < 10 && ft_putchar_fd(fd, n + '0') == -1)
		return (-1);
	else if (n >= 10 && type == 'x' && ft_putchar_fd(fd, n - 10 + 'a') == -1)
		return (-1);
	else if (n >= 10 && type == 'X' && ft_putchar_fd(fd, n - 10 + 'A') == -1)
		return (-1);
	return (0);
}

int	ft_puthex_fd(int fd, unsigned long long n, const char type)
{
	int	len;
	int	temp;

	len = 0;
	if (n >= 16)
	{
		temp = ft_puthex_fd(fd, n / 16, type);
		if (temp == -1)
			return (-1);
		len += temp;
		temp = ft_puthex_fd(fd, n % 16, type);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	else
	{
		if (putchr_hex_fd(fd, n, type) == -1)
			return (-1);
		len++;
	}
	return (len);
}

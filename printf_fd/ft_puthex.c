/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:55:03 by tripham           #+#    #+#             */
/*   Updated: 2024/12/25 11:03:07 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int	putchr_hex(unsigned long long n, const char type)
{
	if (n < 10 && ft_putchar(n + '0') == -1)
		return (-1);
	else if (n >= 10 && type == 'x' && ft_putchar(n - 10 + 'a') == -1)
		return (-1);
	else if (n >= 10 && type == 'X' && ft_putchar(n - 10 + 'A') == -1)
		return (-1);
	return (0);
}

int	ft_puthex(unsigned long long n, const char type)
{
	int	len;
	int	temp;

	len = 0;
	if (n >= 16)
	{
		temp = ft_puthex(n / 16, type);
		if (temp == -1)
			return (-1);
		len += temp;
		temp = ft_puthex(n % 16, type);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	else
	{
		if (putchr_hex(n, type) == -1)
			return (-1);
		len++;
	}
	return (len);
}

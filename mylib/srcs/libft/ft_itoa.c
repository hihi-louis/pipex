/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 04:22:18 by tripham           #+#    #+#             */
/*   Updated: 2024/11/16 21:23:01 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		digits;
	long		num;

	num = (long)n;
	digits = count_digits(n);
	if (n < 0)
	{
		num = -num;
		digits++;
	}
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	while (digits--)
	{
		str[digits] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

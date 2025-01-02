/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:55:05 by tripham           #+#    #+#             */
/*   Updated: 2025/01/02 16:52:46 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putui_fd(int fd, unsigned int n)
{
	int	len;
	int	temp;

	len = 0;
	if (n >= 10)
	{
		temp = ft_putui_fd(fd, n / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	temp = ft_putchar_fd(fd, n % 10 + '0');
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}

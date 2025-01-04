/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:55:01 by tripham           #+#    #+#             */
/*   Updated: 2025/01/04 18:11:12 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(int fd, char *str)
{
	int	len;
	int	temp;

	len = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	while (*str)
	{
		temp = write(fd, str++, 1);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	return (len);
}

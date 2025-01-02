/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:54:56 by tripham           #+#    #+#             */
/*   Updated: 2025/01/02 16:52:40 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putpointer_fd(int fd, unsigned long long p)
{
	int	len;
	int	temp;

	len = 0;
	if (p == 0)
		return (write(fd, "(nil)", 5));
	temp = write(fd, "0x", 2);
	if (temp == -1)
		return (-1);
	len += temp;
	temp = ft_puthex_fd(fd, p, 'x');
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}

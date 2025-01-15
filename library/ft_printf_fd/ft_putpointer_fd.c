/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:54:56 by tripham           #+#    #+#             */
/*   Updated: 2025/01/13 20:31:32 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer_fd(int fd, void *p)
{
	int	len;

	if (!p)
		return (ft_putstr_fd(fd, "0x0"));
	len = ft_putstr_fd(fd, "0x");
	if (len == -1)
		return (-1);
	len += ft_putbase_fd(fd, (unsigned long)p, "0123456789abcdef");
	return (len);
}

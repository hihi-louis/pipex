/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:51:00 by tripham           #+#    #+#             */
/*   Updated: 2025/01/13 20:18:48 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int fd, int n)
{
	long			nb;
	unsigned int	len;
	int				check;

	len = 0;
	check = 0;
	nb = (long)n;
	if (nb < 0)
	{
		if (ft_putchar_fd(fd, '-') == -1)
			return (-1);
		else
			len = 1;
		nb *= -1;
	}
	check = ft_putbase_fd(fd, nb, "0123456789");
	if (check == -1)
		return (-1);
	else
		len += check;
	return (len);
}

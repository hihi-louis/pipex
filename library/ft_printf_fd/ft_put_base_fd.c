/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:21:02 by tripham           #+#    #+#             */
/*   Updated: 2025/01/17 02:59:02 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase_fd(int fd, unsigned long nb, char *base)
{
	unsigned int	len;
	unsigned int	baselen;
	int				check;

	len = 0;
	check = 0;
	baselen = ft_strlen(base);
	if (nb >= baselen)
	{
		check = ft_putbase_fd(fd, nb / baselen, base);
		if (check == -1)
			return (-1);
		else
			len += check;
	}
	if (ft_putchar_fd(fd, *(base + (nb % baselen))) == -1)
		return (-1);
	return (++len);
}

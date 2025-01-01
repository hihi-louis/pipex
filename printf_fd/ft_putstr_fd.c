/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:55:01 by tripham           #+#    #+#             */
/*   Updated: 2025/01/01 18:52:46 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_putstr(int fd, char *str)
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

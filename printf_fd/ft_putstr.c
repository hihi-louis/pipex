/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:55:01 by tripham           #+#    #+#             */
/*   Updated: 2024/12/25 11:03:23 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_putstr(char *str)
{
	int	len;
	int	temp;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		temp = write(1, str++, 1);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	return (len);
}

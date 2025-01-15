/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:55:01 by tripham           #+#    #+#             */
/*   Updated: 2025/01/13 20:31:53 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_putstr_fd(int fd, char *s)
{

	if (!s)
		return (write(fd, "(null)", 6));
	if (write(fd, s, ft_strlen(s)) == -1)
		return (-1);
	return (ft_strlen(s));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:54:56 by tripham           #+#    #+#             */
/*   Updated: 2025/01/18 04:11:55 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putpointer_fd(uintptr_t nbr, int baselen, int low_up)
{
	char	*first;
	char	*second;
	char	*wrote;

	if (nbr == 0)
		wrote = ft_strdup("(nil)");
	else
	{
		first = ft_strdup("0x");
		second = ft_putnbr_base_fd(nbr, baselen, low_up);
		wrote = ft_strjoin(first, second);
		free(first);
		free(second);
	}
	return (wrote);
}

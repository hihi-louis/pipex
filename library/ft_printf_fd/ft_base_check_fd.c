/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_check_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 01:17:26 by tripham           #+#    #+#             */
/*   Updated: 2025/01/18 04:12:59 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_base_check(int baselen, int low_or_up)
{
	char	*binary;
	char	*decimal;
	char	*hexadecimal_lower;
	char	*hexadecimal_upper;

	binary = "01";
	decimal = "0123456789";
	hexadecimal_lower = "0123456789abcdef";
	hexadecimal_upper = "0123456789ABCDEF";
	if (baselen == 2)
		return (binary);
	else if (baselen == 10)
		return (decimal);
	else if (baselen == 16 && low_or_up == 0)
		return (hexadecimal_lower);
	else if (baselen == 16 && low_or_up == 1)
		return (hexadecimal_upper);
	return (0);
}

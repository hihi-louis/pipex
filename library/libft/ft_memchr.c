/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:55:07 by tripham           #+#    #+#             */
/*   Updated: 2024/11/17 00:06:55 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;
	unsigned char	chr;

	s = (unsigned char *)str;
	i = 0;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (s[i] == chr)
			return (s + i);
		i++;
	}
	return (NULL);
}

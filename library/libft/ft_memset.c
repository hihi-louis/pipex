/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:02:47 by tripham           #+#    #+#             */
/*   Updated: 2024/11/17 01:08:16 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	t_byte		*p;
	size_t		i;

	p = (t_byte *)ptr;
	i = 0;
	while (i < num)
	{
		p[i] = (t_byte)value;
		i++;
	}
	return (ptr);
}

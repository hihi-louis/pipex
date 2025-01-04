/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:00:04 by tripham           #+#    #+#             */
/*   Updated: 2024/11/17 00:12:35 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *des, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!des && !src)
		return (NULL);
	if (des == src)
		return (des);
	if (des != src)
	{
		while (i < len)
		{
			((unsigned char *)des)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (des);
}

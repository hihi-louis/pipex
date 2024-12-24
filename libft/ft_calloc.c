/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:39:44 by tripham           #+#    #+#             */
/*   Updated: 2024/11/11 19:39:45 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			total;

	total = count * size;
	if (count && size && total / count != size)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)malloc(total);
	if (!ptr)
		return (NULL);
	while (i < total)
	{
		ptr[i++] = 0;
	}
	return (ptr);
}

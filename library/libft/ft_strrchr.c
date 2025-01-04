/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:24:15 by tripham           #+#    #+#             */
/*   Updated: 2024/11/10 20:52:42 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	chr;

	i = ft_strlen(s);
	chr = c;
	if (s[i] == c)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (chr == s[i])
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

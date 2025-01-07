/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_triple_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:16:03 by tripham           #+#    #+#             */
/*   Updated: 2025/01/07 16:25:45 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_triple_p(void ***arr)
{
	int	i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while ((*arr)[i])
	{
		ft_free_double_p((void **)(*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}
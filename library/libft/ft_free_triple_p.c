/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_triple_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:16:03 by tripham           #+#    #+#             */
/*   Updated: 2025/01/17 02:59:57 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_triple_p(char ***arr)
{
	int	i;

	i = 0;
	if (!arr || !*arr)
		return ;
	if (*arr)
	{
		while ((*arr)[i] != NULL)
			free((*arr)[i++]);
		free(*arr);
		*arr = NULL;
	}
}

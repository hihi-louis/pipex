/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:36:48 by tripham           #+#    #+#             */
/*   Updated: 2024/12/25 21:05:52 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_free_array(char **array) 
{
    int	i;

	i = 0;
    while (array[i]) 
	{
        free(array[i]);
        i++;
    }
    free(array);
}

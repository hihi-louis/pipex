/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all_white_spaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:25:27 by tripham           #+#    #+#             */
/*   Updated: 2025/01/19 14:31:21 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_all_white_spaces(char *command)
{
	while (*command)
	{
		if (*command != 32 && (*command < 9 || *command > 13))
			return (0);
		command++;
	}
	return (1);
}

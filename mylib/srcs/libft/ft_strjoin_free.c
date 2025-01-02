/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:34:45 by tripham           #+#    #+#             */
/*   Updated: 2025/01/02 16:52:01 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char *ft_strjoin_free(char *s1, const char *s2)
{
    char	*result;

	result = ft_strjoin(s1, s2);
    free(s1);
    return result;
}

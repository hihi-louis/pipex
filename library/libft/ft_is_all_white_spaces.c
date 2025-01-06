/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all_white_spaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:25:27 by tripham           #+#    #+#             */
/*   Updated: 2025/01/06 19:25:35 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_all_white_spaces(char *command)
{
    while (*command)
    {
        if (*command != ' ' && *command != '\t' && *command != '\n')
            return 0;
        command++;
    }
    return 1;
}
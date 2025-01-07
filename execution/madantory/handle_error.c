/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:15:23 by tripham           #+#    #+#             */
/*   Updated: 2025/01/07 16:10:02 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	handle_execute_error(char *command_path, char *splitted_command)
{
	
}

void	handle_command_error(char **command, char *message)
{
	ft_printf_fd(2, "pipex: %s: $s\n", *command, message);
	free(*command);
	*command = NULL;
	exit(127);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:15:23 by tripham           #+#    #+#             */
/*   Updated: 2025/01/12 02:00:49 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	handle_execution_error(char *command_path, char **splitted_command)
{
	ft_printf_fd(2, "pipex: %s: %s\n", *splitted_command, strerror(errno));
	if (command_path)
		free(command_path);
	ft_free_double_p((void **)splitted_command);
	exit(126);
}

void	handle_command_error(char **command, char *message)
{
	ft_printf_fd(2, "pipex: %s: $s\n", *command, message);
	free(*command);
	*command = NULL;
	exit(127);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trietpham <trietpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:15:23 by tripham           #+#    #+#             */
/*   Updated: 2025/01/12 15:53:58 by trietpham        ###   ########.fr       */
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

void	handle_open_error(char *file_name, int which_pipe_end)
{
	ft_printf_fd(2, "pipex: %s: %s\n", file_name, strerror(errno));
	close(which_pipe_end);
	exit (1);
}
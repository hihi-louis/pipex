/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:15:23 by tripham           #+#    #+#             */
/*   Updated: 2025/01/15 22:41:34 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	handle_execution_error(char *command_path, char **splitted_command)
{
	ft_printf_fd(2, "pipex : %s: %s\n", *splitted_command, strerror(errno));
	if (command_path)
		free(command_path);
	ft_free_double_p((void **)splitted_command);
	if (errno == EACCES)
		exit (126);
	else if (errno == ENOENT)
		exit (127);
	else if (errno == EPIPE)
		exit (1);
	else
		exit (1);
	// ft_printf_fd(2, "pipex: %s: %s\n", *splitted_command, strerror(errno));
	// if (command_path)
	// 	free(command_path);
	// ft_free_double_p((void **)splitted_command);
	// exit(126);
}

void	handle_command_error(char **command, char *message)
{
	ft_printf_fd(2, "pipex: %s: %s\n", *command, message);
	if (*command)
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

int	access_check(char **splitted_command)
{
	if (open(*splitted_command, F_OK) == 0)
	{
		if (open(*splitted_command, O_DIRECTORY) != -1)
			return (1);
		if (access(*splitted_command, X_OK) == 0)
			return (0);
		else
			return (126);
	}
	return (127);
}

void	is_dir_error(char **splitted_command)
{
	ft_printf_fd(2, "pipex: %s: Is a directory\n", *splitted_command);
	ft_free_double_p((void **)splitted_command);
	exit (126);
}
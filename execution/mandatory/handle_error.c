/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:15:23 by tripham           #+#    #+#             */
/*   Updated: 2025/01/17 02:47:27 by tripham          ###   ########.fr       */
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
	ft_printf_fd(2, "pipex: %s: %s\n", *command, message);
	ft_free_triple_p(&command);
	exit(127);
}

void	handle_open_error(char *file_name, int which_pipe_end)
{
	ft_printf_fd(2, "pipex: %s: %s\n", file_name, strerror(errno));
	close(which_pipe_end);
}

void	handle_fork_error(int *pipe)
{
	close(pipe[0]);
	close(pipe[1]);
	perror("pipex: fork\n");
	exit (1);
}

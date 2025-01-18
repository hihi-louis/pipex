/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:51:29 by tripham           #+#    #+#             */
/*   Updated: 2025/01/17 19:51:13 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static void	first_command(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
		handle_fork_error(pipex->pipe);
	else if (pipex->pid == 0)
	{
		close(pipex->pipe[0]);
		pipex->fd[0] = open(pipex->argv[1], O_RDONLY);
		if (pipex->fd[0] == -1)
		{
			handle_open_error(pipex->argv[1], pipex->pipe[1]);
			exit (1);
		}
		redirect(pipex->fd[0], STDIN_FILENO, pipex->pipe[1], STDOUT_FILENO);
		execute_command(pipex->argv[2], pipex);
	}
	pipex->fork_count++;
	close(pipex->pipe[1]);
}

static void	next_command(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
		handle_fork_error(pipex->pipe);
	else if (pipex->pid == 0)
	{
		close(pipex->pipe[1]);
		pipex->fd[1] = open(pipex->argv[pipex->argc - 1], O_CREAT
				| O_RDWR | O_TRUNC, 0644);
		if (pipex->fd[1] == -1)
		{
			handle_open_error(pipex->argv[pipex->argc - 1], pipex->pipe[0]);
			exit (1);
		}
		redirect(pipex->pipe[0], 0, pipex->fd[1], 1);
		execute_command(pipex->argv[pipex->argc - 2], pipex);
	}
	pipex->fork_count++;
	close(pipex->pipe[0]);
}

void	pipexshell(t_pipex *pipex)
{
	create_pipe(pipex->pipe);
	first_command(pipex);
	next_command(pipex);
	wait_child_process(pipex);
}

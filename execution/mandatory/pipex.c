/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:51:29 by tripham           #+#    #+#             */
/*   Updated: 2025/01/15 23:02:10 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static void first_command(t_pipex *pipex)
{
	child_fork(pipex, pipex->pipe);
	if (pipex->pid == 0)
	{
		close(pipex->pipe[0]);
		pipex->fd[0] = open(pipex->argv[1], O_RDONLY);
		if (pipex->fd[0] == -1)
			handle_open_error(pipex->argv[1], pipex->pipe[1]);
		redirect(pipex->fd[0], STDIN_FILENO, pipex->pipe[1], STDOUT_FILENO);
		execute_command(pipex->argv[2], pipex);
	}
	pipex->fork_counts++;
	close (pipex->pipe[1]);
}

static void	next_command(t_pipex *pipex)
{
	if (pipex->argv[pipex->argc - 2][0] == '\0')
    {
        ft_printf_fd(2, "pipex: : command not found\n");
        pipex->exit_status = 127;  // Lỗi command not found
        return;
    }
	child_fork(pipex, pipex->pipe);
	if (pipex->pid == 0)
	{
		close (pipex->pipe[1]);
		pipex->fd[1] = open (pipex->argv[pipex->argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644); //research more
		if (pipex->fd[1] == -1)
			handle_open_error( pipex->argv[pipex->argc - 1], pipex->pipe[0]);
		redirect(pipex->pipe[0], STDIN_FILENO, pipex->fd[1], STDOUT_FILENO);
		execute_command(pipex->argv[pipex->argc - 2], pipex);
	}
	pipex->fork_counts++;
	close (pipex->pipe[0]);
}

void	pipexshell(t_pipex *pipex)
{
	if (pipe(pipex->pipe) == -1)
	{
		perror("pipex: pipe failed\n");
		exit(1);
	}
	first_command(pipex);
	next_command(pipex);
	child_wait(pipex);
}



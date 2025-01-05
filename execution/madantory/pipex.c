/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:51:29 by tripham           #+#    #+#             */
/*   Updated: 2025/01/05 22:43:34 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static void first_command(t_pipex *pipex)
{
	child_fork(pipex, pipex->pipe);
	if (pipex->pipe = 0)
	{
		close(pipex->pipe[0]);
		pipex->fd[0] = open(pipex->argv[1], O_RDONLY);
		if (pipex->fd[0] < 0)
		{
			ft_printf_fd(2,"pipex: %s: %s\n", pipex->argv[1], strerror(errno));
			close(pipex->pipe[1]);
			exit (1);
		}
		redirect(pipex->fd[0], STDIN_FILENO, pipex->fd[1], STDOUT_FILENO);
		cmd_execuve(pipex->argv[2], pipex);
	}
	
}

void	pipexshell(t_pipex *pipex)
{
	if (pipe(pipex->pipe) == -1)
	{
		perror("pipex: pipe failed\n");
		exit(1);
	}
	first_command(pipex);
}
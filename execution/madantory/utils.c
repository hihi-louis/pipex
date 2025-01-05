/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:29:05 by tripham           #+#    #+#             */
/*   Updated: 2025/01/05 22:04:53 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/pipex.h"

void child_fork(t_pipex *pipex, int *pipe)
{
	pipex->pid = fork();
	if (pipex->pid < 0)
	{
		while (pipex->fork_counts--)
			waitpid(0, &pipex->wait_status, 0);
		perror("pipex: fork failed: \n");
		close(pipe[0]);
		close(pipe[1]);
		exit(1);
	}
}

void	redirect(int infile, int sdtin, int outfile, int stdout)
{
	if (dup2(infile, sdtin) < 0)
	{
		perror("pipex: Redirecting Input Error\n");
		//exit(EXIT_FAILURE);
		exit(1);
	}
	if (dup2(outfile, stdout) < 0)
	{
		perror("pipex: Redirecting Output Error\n");
		exit (1);
	}
	close(infile);
	close(outfile);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:29:05 by tripham           #+#    #+#             */
/*   Updated: 2025/01/08 18:13:31 by tripham          ###   ########.fr       */
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

void	child_wait(t_pipex *pipex)
{
	while (pipex->fork_counts > 0)
	{
		pipex->pid = waitpid(-1, &pipex->wait_status, 0);
		if (pipex->pid > 0)
		{	
			if (WIFEXITED(pipex->wait_status)) // if child process end normally
				pipex->exit_status = WEXITSTATUS(pipex->wait_status); // got the code of exit
			else if (WIFSIGNALED(pipex->wait_status)) // if child process end with signal
				pipex->exit_status = 128 + WTERMSIG(pipex->wait_status); // assign signal code with 128
			pipex->fork_counts--; 
		}
		else if (pipex->pid == -1)
		{
			perror("pipex: Waitpid Error");
			break;
		}
	}
}

int	skip_quotes(char *command, int i)
{
	char quote;

	quote = command[i];
	i++;
	while (command[i] && command[i] != quote)
		i++;
	if (command[i] != quote)
	{
		ft_printf_fd(2, "pipex: Missing %c\n", quote);
		exit (1);
	}
	return (i);
}

int skip_words(char *command, int i)
{
	while (command[i] && command[i] != 32 && command[i] != 34 && command[i] != 39)
	{
		if (command[i] == '\\' && command[i + 1] != '\0')
			i += 2;
		else
			i++;
	}
	return (i);
}

char	extract_word(char *command, int i)
{
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:29:05 by tripham           #+#    #+#             */
/*   Updated: 2025/01/17 02:54:24 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	redirect(int infile, int stdin, int outfile, int stdout)
{
	if (infile >= 0 && dup2(infile, stdin) < 0)
	{
		perror("pipex: Redirecting Error (input)");
		close(infile);
		close(outfile);
		exit(1);
	}
	if (outfile >= 0 && dup2(outfile, stdout) < 0)
	{
		perror("pipex: Redirecting Error (output)");
		close(infile);
		close(outfile);
		exit(1);
	}
	close(infile);
	close(outfile);
}

int	skip_quotes(char *command, int i)
{
	char	quote;

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

int	skip_words(char *command, int i)
{
	while (command[i] && command[i] != 32 && command[i] != 34
		&& command[i] != 39)
	{
		if (command[i] == '\\' && command[i + 1] != '\0')
			i += 2;
		else
			i++;
	}
	return (i);
}

void	create_pipe(int *pipe_id)
{
	if (pipe(pipe_id) == -1)
	{
		perror("pipex: pipe\n");
		exit (1);
	}
}

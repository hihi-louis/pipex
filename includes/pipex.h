/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 02:57:35 by tripham           #+#    #+#             */
/*   Updated: 2025/01/17 18:55:53 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../library/libft/libft.h"
# include "../library/ft_printf_fd/ft_printf.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct s_pipex
{
	int				argc;
	int				fd[2];
	int				pipe[2];
	int				error;
	char			**argv;
	char			**envp;
	pid_t			pid;
	int				fork_count;
	int				status_of_wait;
	int				status_of_exit;
}	t_pipex;

void	redirect(int infile, int sdtin, int outfile, int stdout);
void	handle_command_error(char **command, char *message);
void	handle_execution_error(char *command_path, char **splitted_command);
int		skip_words(char *command, int i);
int		skip_quotes(char *command, int i);
char	**split_command(char *command);
char	*found_command_path(char **splitted_command, char **envp);
void	execute_command(char *command, t_pipex *pipex);
void	pipexshell(t_pipex *pipex);
void	handle_open_error(char *file_name, int which_pipe_end);
void	handle_fork_error(int *pipe);
void	create_pipe(int *pipe_id);
void	wait_child_process(t_pipex *pipex);
#endif

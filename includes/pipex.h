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
	int				argc;          // Number of arguments
	int				fd[2];         // File descriptors (e.g., input/output files)
	int				pipe[2];       // Pipe file descriptors (read/write ends)
	int				exit_status;   // Stores the final exit status
	int				wait_status;   // Stores the status returned by waitpid()
	int				fork_counts;    // Counter for the number of forks
	//int				*track;        // Pointer to track processes or resource handling
	char			**argv;        // Command-line arguments
	char			**envp;        // Environment variables
	pid_t			pid;           // Process ID for forked child process
}	t_pipex;

void child_fork(t_pipex *pipex, int *pipe);

void	redirect(int infile, int sdtin, int outfile, int stdout);

void	child_wait(t_pipex *pipex);

void	handle_command_error(char **command, char *message);

int skip_words(char *command, int i);

int	skip_quotes(char *command, int i);

char	**split_command(char *command);
#endif
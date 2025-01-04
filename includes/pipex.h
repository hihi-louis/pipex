#ifndef PIPEX_H
# define PIPEX_H

# include "mylib.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		error;
	int		fd[2];
	int		pipe_id[2];
	pid_t	pid;
}	t_pipex;



char *ft_access(char *cmd, char **envp);
const char *ft_strerror(int errnum);
void ft_perror(int fd, const char *message);

#endif
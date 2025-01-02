#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char *ft_access(char *cmd, char **envp);
const char *ft_strerror(int errnum);
void ft_perror(int fd, const char *message);

#endif
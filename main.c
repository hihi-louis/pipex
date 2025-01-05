#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct s_pipex {
    pid_t pid;           // Process ID
    int fork_counts;     // Number of forks
    int wait_status;     // Wait status for processes
} t_pipex;

void child_fork(t_pipex *pipex, int *pipe)
{
    pipex->pid = fork();
    if (pipex->pid < 0)  // If fork fails
    {
        while (pipex->fork_counts--)
            waitpid(0, &pipex->wait_status, 0);  // Wait for other processes if any
        perror("pipex: fork failed: \n");
        close(pipe[0]);  // Close pipe ends
        close(pipe[1]);
        exit(1);  // Exit with error
    }
}

int main()
{
    t_pipex pipex;
    int pipe_fds[2];  // Pipe ends

    // Initialize pipe
    if (pipe(pipe_fds) == -1)
    {
        perror("Error creating pipe");
        exit(1);
    }

    pipex.fork_counts = 1;  // Set to 1 for a single fork

    printf("Forking process...\n");

    // Test child_fork
    child_fork(&pipex, pipe_fds);

    if (pipex.pid == 0)  // Child process
    {
        printf("Child process (PID: %d) running.\n", getpid());
        close(pipe_fds[0]);  // Close unused pipe read end
        close(pipe_fds[1]);  // Close write end after use
        exit(0);  // Exit child process
    }
    else  // Parent process
    {
        printf("Parent process (PID: %d) waiting for child.\n", getpid());
        close(pipe_fds[0]);  // Close unused pipe read end
        close(pipe_fds[1]);  // Close unused pipe write end
        waitpid(pipex.pid, NULL, 0);  // Wait for child process to finish
        printf("Child process finished.\n");
    }

    return 0;
}

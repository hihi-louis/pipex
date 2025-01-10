#include "./includes/pipex.h"

static char	**found_envp_path(char **envp, char **command)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			envp += i;
		if (!envp[i])
			handle_command_error(command, "No such file or directory");
	}
	return (ft_split(envp[i], ':'));
}

int main(int argc, char **argv, char **envp)
{
    char *command[] = { "ls", NULL };
    char **paths = found_envp_path(envp, command);

    printf("Paths found in PATH:\n");
    for (int i = 0; paths[i] != NULL; i++)
    {
        printf("Path %d: %s\n", i + 1, paths[i]);
        free(paths[i]);
    }
    free(paths);

    return 0;
}
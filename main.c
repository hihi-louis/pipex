#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "pipex.h"
// ft_access
int main(int argc, char **argv, char **envp)
{
	char	*result;
	
	if (argc != 2)
	{
		printf("Usage: %s <command>\n", argv[0]);
        return (1);
	}

	result = ft_access(argv[1], envp);
	if (result)
    {
        printf("Executable path: %s\n", result);
        free(result);
    }
	else
	{
		 printf("Command not found: %s\n", argv[1]);
	}
	return (0);
}
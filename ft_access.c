/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:18:37 by tripham           #+#    #+#             */
/*   Updated: 2024/12/25 21:29:36 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *ft_access(char *cmd, char **envp)
{
	char		**paths;
	char	*env_path;
	char	*test_path;
	int		i;

	env_path = NULL;
	i = 0;
	while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            env_path = envp[i] + 5;
            break;
        }
        i++;
    }
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path, ':');
	if (!paths)
		return (NULL);

	i = 0;
	while (paths[i])
	{
		test_path = ft_strjoin(paths[i], "/");
		test_path = ft_strjoin(test_path, cmd);
		if (access(test_path, X_OK) == 0)
		{
			ft_free_array(paths);
			return (test_path);
		}
		free(test_path);
		i++;
	}
	ft_free_array(paths);
	return (NULL);
}

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
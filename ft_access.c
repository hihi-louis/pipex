/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trietpham <trietpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:18:37 by tripham           #+#    #+#             */
/*   Updated: 2025/01/01 10:47:53 by trietpham        ###   ########.fr       */
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


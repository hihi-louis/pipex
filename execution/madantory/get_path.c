/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:44:37 by tripham           #+#    #+#             */
/*   Updated: 2025/01/11 03:23:56 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static char	**found_envp_path(char **envp, char **command)
{
	int i = 0;

	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return ft_split(envp[i] + 5, ':');  // Tách các đường dẫn khi tìm thấy "PATH="
		i++;
	}
	handle_command_error(command, "No such file or directory");
	return NULL;
}

static char	*join_command_path(char *envp_path, char *command)
{
	char	*command_directories;
	char	*command_path;

	command_directories = ft_strjoin(envp_path, "/");
	if (!command_directories)
		return (NULL);
	command_path = ft_strjoin(command_directories, command);
	if (!command_path)
	{
		free(command_directories);
		return (NULL);
	}
	free(command_directories);
	return (command_path);
}

static char	*get_command_path(char **envp_paths, char *command)
{
	char	*command_path;

	while (*envp_paths)
	{
		command_path = join_command_path(*(envp_paths)++, command);
		if (!command_path)
			{
				ft_free_double_p(envp_paths);
				return (NULL);
			}
		if (access(command_path, F_OK) == 0)
			return (command_path);
		free(command_path);
	}
	return (NULL);
}

char	*found_command_path(char **splitted_command, char **envp)
{
	char	**envp_paths;
	char	*command_path;

	if (ft_strchr(*splitted_command, '/'))
	{
		if(access(*splitted_command, F_OK) == 0)
			return (ft_strdup(*splitted_command));
		else
			handle_command_error(splitted_command, "No such file or directory");
	}
	envp_paths = found_envp_path(envp, splitted_command);
	if (!envp_paths)
		return (NULL);
	command_path = get_command_path(envp_paths, *splitted_command);
	// if (!command_path)
	// 	handle_command_error(splitted_command, "Command not found");
	ft_free_double_p(envp_paths);
	return (command_path);
}

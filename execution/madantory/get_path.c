/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:44:37 by tripham           #+#    #+#             */
/*   Updated: 2025/01/10 20:36:30 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

char	*found_command_path(char **splitted_command, char **envp)
{
	char	
}

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


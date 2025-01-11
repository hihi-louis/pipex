/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:53:34 by tripham           #+#    #+#             */
/*   Updated: 2025/01/11 05:50:24 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
void	execute_command(char *command, t_pipex *pipex)
{
	char	**splitted_command;
	char	*command_path;

	splitted_command = split_command(command);
	if (!splitted_command)
		exit (1);
	command_path = found_command_path(splitted_command, pipex->envp);
	if (!command_path)
		handle_command_error(splitted_command, "Command not found");
	execve(splited_command, command, pipex->envp);
	handle_execution_error(command_path, splitted_command);
}

static void	execute_first_command(char *command, t_pipex *pipex)
{
	pipex->pid
}
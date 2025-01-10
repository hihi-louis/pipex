/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:53:34 by tripham           #+#    #+#             */
/*   Updated: 2025/01/10 16:44:24 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
void	execute_command(char *argv, t_pipex *pipex)
{
	char		**splitted_command;
	char	*command_path;

	splitted_command = split_command(argv);
	if (!splitted_command)
		exit (1);
	command_path = get_path();
}
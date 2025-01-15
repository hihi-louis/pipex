/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 03:24:04 by tripham           #+#    #+#             */
/*   Updated: 2025/01/14 19:29:21 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	
	if (argc != 5)
	{
		ft_printf_fd(2, "pipex: Invalid number of arguments.\n");
		exit(1);
	}
	pipex.argc = argc;
	pipex.argv = argv;
	pipex.envp = envp;
	pipex.exit_status = 0;
	pipex.fork_counts = 0;
	pipexshell(&pipex);
	exit(pipex.exit_status);
}
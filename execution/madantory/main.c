/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 03:24:04 by tripham           #+#    #+#             */
/*   Updated: 2025/01/04 17:42:01 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	
	if (argc != 5)
	{
		ft_printf_fd(2, "pipex: Invalid number of arguments.\n");
		exit(1);
	}
	pipex.ac = argc;
	pipex.av = argv;
	pipex.envp = envp;
	pipex.exit_status = 0;
	pipex.fork_times = 0;
	pipexshell(&pipex);
	exit(pipex.exit_status);	
}
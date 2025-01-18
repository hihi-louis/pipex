/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 03:24:04 by tripham           #+#    #+#             */
/*   Updated: 2025/01/17 19:17:54 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_printf_fd(2, "pipex: Invalid number of arguments.\n");
		exit(1);
	}
	pipex.argc = argc;
	pipex.argv = argv;
	pipex.envp = envp;
	pipex.status_of_exit = 0;
	pipex.fork_count = 0;
	pipexshell(&pipex);
	exit(pipex.status_of_exit);
}

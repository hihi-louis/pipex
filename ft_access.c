/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:18:37 by tripham           #+#    #+#             */
/*   Updated: 2024/12/24 17:26:07 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

char *ft_access(char *cmd, char **envp)
{
	char		**paths;
	char	*env_path;
	char	*test_path;
	int		i;

	env_path = NULL;
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) == 0)
	{
		env_path = envp[i] + 5;
		i++;	
	}
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path, ':');
}
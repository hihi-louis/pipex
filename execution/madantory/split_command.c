/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:12:26 by tripham           #+#    #+#             */
/*   Updated: 2025/01/07 21:10:32 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static int	count_words(char *command)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (command[i])
	{
		if (command[i] == 39 || command[i] == 34)
		{
			words++;
			i = skip_quotes(command, i);
			i++; 
		}
		else if (command[i] != 32)
		{
			words++;
			i = skip_words(command, i);	
		}
		else
			i++;
	}
	return (words);
}

statis char	**split_word(char *command, char **array, int words, int order)
{
	
}

char	**split_command(char *command)
{
	int		words;
	char	**array;

	if (!command)
		return (NULL);
	if (ft_is_all_white_spaces(command))
		handle_command_error(&command, "Command not found");
	words = count_words(command);
	array = (char **)ft_calloc((word + 1), sizeof(char *);
	if (!array)
		return (NULL);
	array = split_word()
}
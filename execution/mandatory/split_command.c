/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:12:26 by tripham           #+#    #+#             */
/*   Updated: 2025/01/17 19:50:38 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static int	words_count(char *command)
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

static char	*extract_word(char *command, int len)
{
	char	*word;
	int		i;
	int		j;

	word = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	if (!word)
		return (NULL);
	while (i < len)
	{
		if ((command[0] == 34 || command[0] == 39) && command[i] == command[0])
			i++;
		else if (command[0] != 34 && command[0] != 39 && command[i] == 32)
			i++;
		else
		{
			if (command[0] != 34 && command[0] != 39 && command[i] == '\\')
				i++;
			word[j++] = command[i++];
		}
	}
	word[j] = '\0';
	return (word);
}

static char	**split_word(char *command, char **array, int words, int order)
{
	int		i;
	char	quote;

	while (++order < words)
	{
		while (*command == 32)
			command++;
		i = 0;
		quote = *command;
		if (*command == 34 || *command == 39)
			while (command[++i] != quote)
				;
		else
			i = skip_words(command, 0);
		array[order] = extract_word(command, i);
		if (!array[order])
		{
			ft_free_double_p((void **)array);
			return (NULL);
		}
		if (*command == 39 || *command == 34)
			i++;
		command += i;
	}
	return (array);
}

char	**split_command(char *command)
{
	int		words;
	char	**array;

	if (!command || *command == '\0')
	{
		ft_printf_fd (2, "pipex: : command not found\n");
		return (NULL);
	}
	if (ft_is_all_white_spaces(command))
	{
		ft_printf_fd(2, "pipex: %s: %s\n", command, "command not found");
		exit(127);
	}
	words = words_count(command);
	array = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!array)
		return (NULL);
	array = split_word(command, array, words, -1);
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 03:57:32 by tripham           #+#    #+#             */
/*   Updated: 2024/11/17 01:28:12 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t	count;

	count = 0;
	if (!s || !*s)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char	*ft_extract_word(char const *s, char c)
{
	char	*word;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = ft_substr(s, 0, len);
	return (word);
}

static void	ft_free_word(char **split, size_t count)
{
	size_t	i;

	i = 0;
	if (!split)
		return ;
	while (i < count)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

static char	**s_process(char const *s, char c, size_t i, char **result)
{
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = ft_extract_word(s, c);
			if (!result[i])
			{
				ft_free_word(result, i);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		word_count;
	size_t		i;

	if (!s)
		return (NULL);
	word_count = ft_countword(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	result = s_process(s, c, i, result);
	return (result);
}

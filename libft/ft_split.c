/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:43:49 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/13 14:06:54 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	word;
	size_t	i;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static char	*ft_insert_word(char const *s, char c, int *i)
{
	size_t	length;
	size_t	start;
	size_t	j;
	char	*word;

	start = *i;
	while (s[start] == c)
		start++;
	length = 0;
	while (s[start + length] != '\0' && s[start + length] != c)
		length++;
	word = malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);
	j = 0;
	while (j < length)
	{
		word[j] = s[start + j];
		j++;
	}
	word[length] = '\0';
	*i = start + length;
	return (word);
}

static void	ft_free(char **s, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	i;
	size_t	j;
	char	**result;

	if (!s)
		return (NULL);
	word_count = ft_count_word(s, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count)
	{
		result[j] = ft_insert_word(s, c, (int *)&i);
		if (result[j] == NULL)
		{
			ft_free(result, j);
			return (NULL);
		}
		j++;
	}
	result[j] = (NULL);
	return (result);
}

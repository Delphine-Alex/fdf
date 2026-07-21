/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:21:55 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/10 18:28:02 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_char_matches(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 && !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_char_matches(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (start < end && ft_char_matches(s1[end - 1], set))
		end--;
	copy = malloc(sizeof(char) * ((end - start) + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		copy[i] = s1[start];
		i++;
		start++;
	}
	copy[i] = '\0';
	return (copy);
}

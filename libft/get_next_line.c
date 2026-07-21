/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:27:48 by dpaiva            #+#    #+#             */
/*   Updated: 2025/01/25 16:08:52 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *extract_line(char *line)
{
	size_t i;
	char *stash;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (0);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*stash == 0)
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}

static char *read_and_stash(int fd, char *stash, char *buffer)
{
	ssize_t nb;
	char *tmp;

	nb = 1;
	while (nb > 0)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1)
		{
			free(stash);
			return (NULL);
		}
		if (nb == 0)
			break;
		buffer[nb] = '\0';
		if (stash == NULL)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (stash);
}

char *get_next_line(int fd)
{
	static char *stash[MAX_FD];
	char *line;
	char *buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(stash[fd]);
		buffer = NULL;
		stash[fd] = NULL;
		return (NULL);
	}
	line = read_and_stash(fd, stash[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (line == NULL)
		return (NULL);
	stash[fd] = extract_line(line);
	return (line);
}
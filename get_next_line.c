/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpcarvalho <jpcarvalho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:37:16 by jhorta-c          #+#    #+#             */
/*   Updated: 2024/02/02 17:45:12 by jpcarvalho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *text, char *buffer)
{
	char	*tmp;
	int		i_read;

	i_read = 1;
	while (i_read)
	{
		i_read = read(fd, buffer, BUFFER_SIZE);
		if (i_read < 0)
			return (NULL);
		if (i_read == 0)
			break ;
		buffer[i_read] = '\0';
		if (!text)
			text = ft_strdup("");
		tmp = text;
		text = ft_strjoin(tmp, buffer);
		free (tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (text);
}

char	*ft_freeline(char *string)
{
	char	*line;
	int		i;

	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	if (string[i] == '\0')
		return (NULL);
	line = ft_substr(string, i + 1, ft_strlen(string) - i);
	if (*line == '\0')
	{
		free(line);
		line = NULL;
	}
	string[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_read_file(fd, text, buffer);
	free (buffer);
	buffer = NULL;
	if (!line)
	{
		free(text);
		text = NULL;
		return (NULL);
	}
	text = ft_freeline(line);
	return (line);
}

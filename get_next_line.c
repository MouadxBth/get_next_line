/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:15:51 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/11 17:06:18 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_index_of(char c, char *str)
{
	int index;

	if (!str)
		return (-1);
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	if (!c && !str[index])
		return (index);
	return (-1);
}

char	*ft_fill_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_index_of('\n', buffer) >= 0)
			break ;
	}
	free(buffer);
	return (stash);
}

char	*ft_process_stash(char **stash)
{
	int	new_line;
	char	*line;
	char	*temp;

	new_line = ft_index_of('\n', *stash);
	temp = ft_substr(*stash, 0, new_line + 1);
	line = ft_strjoin(NULL, temp);
	free(temp);
	temp = ft_substr(*stash, new_line + 1, BUFFER_SIZE);
	free(*stash);
	*stash = temp;
	return (line);
}	

char	*get_next_line(int fd)
{
	static char	*stash;

	stash = ft_fill_stash(fd, stash);
	if (!stash || !*stash)
		return (NULL);
	return (ft_process_stash(&stash));
}

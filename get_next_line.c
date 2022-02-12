/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:15:51 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/12 21:11:01 by mbouthai         ###   ########.fr       */
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

char	*ft_extract_line(char *stash)
{
	char	*line;
	char	*temp;
	int	new_line;

	if (!stash)
		return (NULL);
	new_line = ft_index_of('\n', stash);
	if (new_line >= 0)
	{
		temp = ft_substr(stash, 0, new_line + 1);
		line = ft_strjoin(NULL, temp);
		free(temp);
	}
	else
		line = ft_strjoin(NULL, stash);
	return (line);
}

char	*ft_process_stash(char *stash)
{
	char	*temp;
	int	new_line;

	if (!stash)
		return (NULL);
	new_line = ft_index_of('\n', stash);
	if (new_line < 0)
	{
		free(stash);
		return (NULL);
	}
	temp = ft_substr(stash, new_line + 1, ft_strlen(stash));
	free(stash);
	stash = temp;
	return (stash);
}	

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	if (!*stash)
	{
		free(stash);
		return (NULL);
	}
	line = ft_extract_line(stash);
	stash = ft_process_stash(stash);
	return (line);
}

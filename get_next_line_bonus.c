/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:44:48 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/06 21:12:46 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_fill_stash(int fd, char *stash, int *new_line)
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
		if (bytes_read < 0)
		{
			free(stash);
			break ;
		}
		buffer[bytes_read] = '\0';
		stash = ft_special_join(stash, buffer);
		*new_line = ft_find('\n', stash);
		if (*new_line >= 0)
			break ;
	}
	free(buffer);
	return (stash);
}

char	*ft_handle_stash(char *stash, int new_line)
{
	size_t	length;
	char	*result;
	int		index;

	if (new_line >= 0)
		length = new_line + 1;
	else
		length = ft_strlen(stash);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
	{
		free(stash);
		return (NULL);
	}
	index = -1;
	if (new_line >= 0)
		while (++index <= new_line)
			result[index] = stash[index];
	else
		while (stash[++index])
			result[index] = stash[index];
	result[index] = '\0';
	return (result);
}

char	*ft_process_stash(char *stash, int new_line)
{
	char	*temp;
	int		temp_length;

	temp = NULL;
	if (new_line >= 0)
	{
		temp_length = 0;
		while (stash[new_line + temp_length + 1])
			temp_length++;
		if (temp_length)
			temp = ft_cut(stash, new_line + 1, temp_length);
	}
	free(stash);
	stash = temp;
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*result;
	int			new_line;

	if (fd < 0)
		return (NULL);
	stash[fd] = ft_fill_stash(fd, stash[fd], &new_line);
	if (!stash[fd])
		return (NULL);
	if (!*stash[fd])
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	result = ft_handle_stash(stash[fd], new_line);
	stash[fd] = ft_process_stash(stash[fd], new_line);
	return (result);
}

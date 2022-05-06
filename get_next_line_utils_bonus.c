/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:06:45 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/06 21:12:58 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ft_find(char c, char *str)
{
	int	index;

	if (!str)
		return (-1);
	index = 0;
	while (str[index])
	{
		if (c == str[index])
			return (index);
		index++;
	}
	if (!c && !str[index])
		return (index);
	return (-1);
}

char	*ft_special_join(char *first, char *second)
{
	size_t	first_length;
	size_t	second_length;
	char	*result;
	int		index;

	if (!first && !second)
		return (NULL);
	first_length = ft_strlen(first);
	second_length = ft_strlen(second);
	result = (char *)malloc(sizeof(char) * (first_length + second_length + 1));
	if (!result)
		return (NULL);
	index = -1;
	while (first && first[++index])
		result[index] = first[index];
	index = -1;
	while (second && second[++index])
		result[first_length + index] = second[index];
	free(first);
	result[first_length + index] = '\0';
	return (result);
}

char	*ft_cut(char *str, int start, int length)
{
	char	*result;
	int		index;

	if (!str)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (str[index + start] && index < length)
	{
		result[index] = str[index + start];
		index++;
	}
	result[index] = '\0';
	return (result);
}

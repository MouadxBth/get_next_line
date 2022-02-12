/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:59:22 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/13 00:14:38 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

int		ft_find(char c, char *str);
char	*ft_fill_stash(int fd, char *stash);
char	*ft_extract_line(char *stash);
char	*ft_process_stash(char *stash);

char	*get_next_line(int fd);

#endif

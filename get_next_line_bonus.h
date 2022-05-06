/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:06:24 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/06 21:14:43 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

size_t	ft_strlen(char *str);
int		ft_find(char c, char *str);
char	*ft_special_join(char *first, char *second);
char	*ft_cut(char *str, int start, int length);

char	*ft_fill_stash(int fd, char *stash, int *new_line);
char	*ft_handle_stash(char *stash, int new_line);
char	*ft_process_stash(char *stash, int new_line);

char	*get_next_line(int fd);

#endif

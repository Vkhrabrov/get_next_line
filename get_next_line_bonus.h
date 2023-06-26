/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:02:25 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/04/25 00:24:13 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef FD
#  define FD OPEN_MAX
# endif

size_t		ft_strlen(const char *c);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
char		*true_free(char **ptr);

#endif

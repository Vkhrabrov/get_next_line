/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:40 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/06/26 21:19:33 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*true_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*storage_update(char **storage, int i)
{
	char	*temp;

	temp = ft_strdup(&(*storage)[i]);
	if (!temp)
		return (true_free(storage));
	free(*storage);
	*storage = temp;
	return (*storage);
}

char	*filling_line(char *storage, char *line, char **storage_ptr)
{
	size_t	i;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\n' || storage[i] == '\0')
	{
		if (ft_strchr(storage, '\n'))
			i++;
		line = malloc(sizeof(char) * (i + 1));
		if (!line)
			return (line);
		ft_strlcpy(line, storage, i + 1);
	}
	*storage_ptr = storage_update(&storage, i);
	if (*storage_ptr == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*filling_storage(int fd, char *storage)
{
	char	*new_storage;
	int		num_bytes;
	char	*buffer;

	num_bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (true_free(&storage));
	*buffer = '\0';
	while (num_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes == -1)
		{
			free(buffer);
			return (true_free(&storage));
		}
		buffer[num_bytes] = '\0';
		new_storage = ft_strjoin(storage, buffer);
		storage = new_storage;
	}
	if (buffer)
		free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	storage = filling_storage(fd, storage);
	if (!storage || *storage == '\0')
		return (true_free(&storage));
	line = filling_line(storage, line, &storage);
	if (!line)
		return (true_free(&storage));
	return (line);
}

int main(int argc, char **argv)
{
     int fd, line_count;
     char *line;
    
     line_count = 1;
    line = "";
     if (argc == 2)
    {
         fd = open(argv[1], O_RDONLY);
         while (line != NULL)
         {
             line = get_next_line(fd);
            if (!line)
                break ;
            printf("Line #%d => %s\n", line_count, line);

         }
         line_count++;
         close(fd);
     }
     return (0);
 }

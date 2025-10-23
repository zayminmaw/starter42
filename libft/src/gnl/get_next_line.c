/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmin <zmin@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:49:48 by zmin              #+#    #+#             */
/*   Updated: 2025/09/10 21:49:50 by zmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*gnl_load_buffer(int fd, char *left_c, char *buffer);
static char	*gnl_fill_line(char *line_buff);

/*
** Reads a line from a file descriptor.
** 
** Parameters:
**   fd - The file descriptor to read from
** 
** Return:
**   Returns a string containing the next line (including newline),
**   or NULL if EOF or error.
** 
** Edge cases:
**   - Returns NULL if fd < 0 or BUFFER_SIZE <= 0
**   - Supports multiple file descriptors (up to FD_OPEN_MAX)
**   - Preserves leftover characters between calls using static array
**   - Returns NULL on read error or EOF
**   - Frees resources on error
**   - Helper function gnl_load_buffer reads and accumulates data
**   - Helper function gnl_fill_line extracts next line and updates leftover
*/
char	*get_next_line(int fd)
{
	static char	*left_c[FD_OPEN_MAX];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(left_c[fd]);
		left_c[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = gnl_load_buffer(fd, left_c[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_c[fd] = gnl_fill_line(line);
	return (line);
}

/*
** Helper function to read data from file descriptor into buffer.
** 
** Parameters:
**   fd     - File descriptor to read from
**   left_c - Leftover characters from previous call
**   buffer - Buffer for reading data
** 
** Return:
**   Returns accumulated string with data read,
**   or NULL on error.
** 
** Edge cases:
**   - Reads until newline found or EOF
**   - Joins leftover with newly read data
**   - Returns NULL on read error
**   - Frees and reallocates string as needed
*/
static char	*gnl_load_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	buf_read;
	char	*tmp;

	buf_read = 1;
	while (buf_read > 0)
	{
		buf_read = read(fd, buffer, BUFFER_SIZE);
		if (buf_read < 0)
		{
			free(left_c);
			return (NULL);
		}
		else if (buf_read == 0)
			break ;
		buffer[buf_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

/*
** Helper function to extract one line and save the rest.
** 
** Parameters:
**   line_buff - String containing current data
** 
** Return:
**   Returns leftover string after extracting the line,
**   or NULL if no leftover data.
** 
** Edge cases:
**   - Finds newline character and splits at that point
**   - Returns NULL if no data after newline
**   - Terminates line at newline+1 position
**   - Frees leftover if it's empty
**   - Uses ft_substr to extract remaining data
*/
static char	*gnl_fill_line(char *line_buff)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	while (line_buff[i] != '\n' && line_buff[i] != '\0')
		i++;
	if (line_buff[i] == 0 || line_buff[i + 1] == 0)
		return (NULL);
	left_c = ft_substr(line_buff, i + 1, ft_strlen(line_buff) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line_buff[i + 1] = 0;
	return (left_c);
}

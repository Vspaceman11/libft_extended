/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:53:47 by vpushkar          #+#    #+#             */
/*   Updated: 2025/04/09 16:16:04 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *line_buffer);
static char	*ft_extract_line(char *line_buffer, char *remainder);
static char	*ft_nl_case(char *line_buffer, char *remainder, char *newline_ptr);

/**
 * @brief Reads the next line from a file descriptor.
 *
 * This function reads from the file descriptor @p fd and returns the next
 * line, including the newline character ('\n') if present. The line is
 * returned as a dynamically allocated string. If there is nothing more
 * to read or an error occurs, NULL is returned.
 *
 * @param fd The file descriptor to read from.
 * @return A pointer to the next line, or NULL if no line is available
 * 			or an error occurs.
 */
char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		*line_buffer;
	char		*final_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (remainder[0] != '\0')
		line_buffer = ft_strdup_gnl(remainder);
	else
	{
		line_buffer = (char *)malloc(1);
		if (!line_buffer)
			return (NULL);
		line_buffer[0] = '\0';
	}
	line_buffer = ft_read_line(fd, line_buffer);
	if (!line_buffer || line_buffer[0] == '\0')
	{
		free(line_buffer);
		remainder[0] = '\0';
		return (NULL);
	}
	final_line = ft_extract_line(line_buffer, remainder);
	return (final_line);
}

/**
 * @brief Reads from the file descriptor until a newline or EOF.
 *
 * This function continues reading from @p fd and appends the content to
 * @p line_buffer until a newline character is found or end-of-file is reached.
 * The buffer is dynamically resized as needed.
 *
 * @param fd The file descriptor to read from.
 * @param line_buffer A buffer holding previously read data. Will be expanded
 * 			with new content.
 * @return A pointer to the updated line buffer, or NULL on error.
 */
static char	*ft_read_line(int fd, char *line_buffer)
{
	char	read_buffer[BUFFER_SIZE + 1];
	char	*tmp;
	ssize_t	bytes_read;

	if (line_buffer && ft_strchr_gnl(line_buffer, '\n'))
		return (line_buffer);
	bytes_read = BUFFER_SIZE;
	while (ft_strchr_gnl(line_buffer, '\n') == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line_buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		read_buffer[bytes_read] = '\0';
		tmp = line_buffer;
		line_buffer = ft_strjoin_gnl(tmp, read_buffer);
		free(tmp);
		if (!line_buffer)
			return (NULL);
	}
	return (line_buffer);
}

/**
 * @brief Extracts a line from the buffer and updates the remainder.
 *
 * If a newline character is found, the line is extracted up to and including
 * the newline. The remaining content is stored in @p remainder.
 * If no newline is found, the entire buffer is returned as the line.
 *
 * @param line_buffer The buffer containing the full or partial line.
 * @param remainder The buffer where leftover content (after newline) is stored.
 * @return A pointer to the extracted line, or NULL on allocation failure.
 */
static char	*ft_extract_line(char *line_buffer, char *remainder)
{
	char	*newline_ptr;
	char	*return_line;

	if (!line_buffer || line_buffer[0] == '\0')
	{
		free(line_buffer);
		remainder[0] = '\0';
		return (NULL);
	}
	newline_ptr = ft_strchr_gnl(line_buffer, '\n');
	if (newline_ptr)
	{
		return_line = ft_nl_case(line_buffer, remainder, newline_ptr);
		free(line_buffer);
	}
	else
	{
		remainder[0] = '\0';
		return_line = line_buffer;
	}
	return (return_line);
}

/**
 * @brief Handles line extraction when a newline is present in the buffer.
 *
 * This function allocates and returns a string containing the line up to and
 * including the newline character. It also stores the remaining part of the
 * buffer into @p remainder.
 *
 * @param line_buffer The buffer with the complete line and possibly more.
 * @param remainder Buffer to store remaining content after the newline.
 * @param newline_ptr Pointer to the newline character in @p line_buffer.
 * @return A pointer to the extracted line, or NULL if allocation fails.
 */
static char	*ft_nl_case(char *line_buffer, char *remainder, char *newline_ptr)
{
	char	*return_line;
	size_t	line_len;

	line_len = (newline_ptr - line_buffer) + 1;
	ft_strlcpy_gnl(remainder, newline_ptr + 1, BUFFER_SIZE + 1);
	return_line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (!return_line)
	{
		remainder[0] = '\0';
		return (NULL);
	}
	ft_strlcpy_gnl(return_line, line_buffer, line_len + 1);
	return (return_line);
}

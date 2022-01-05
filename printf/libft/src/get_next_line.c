/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 06:50:30 by jcaetano          #+#    #+#             */
/*   Updated: 2021/10/08 17:02:31 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*ft_read_fd(int fd, char *stack_backup, char *heap_buffer);
static char	*ft_format_line(char *line);
static char	*ft_format_backup(char *line);

char	*get_next_line(int fd)
{
	static char	*stack_backup[MAX_FD];
	char		*heap_buffer;
	char		*line;

	if ((fd < 0) || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	heap_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!heap_buffer)
	{
		free(heap_buffer);
		return (NULL);
	}
	stack_backup[fd] = ft_read_fd(fd, stack_backup[fd], heap_buffer);
	if (!stack_backup[fd])
		return (NULL);
	line = ft_format_line(stack_backup[fd]);
	stack_backup[fd] = ft_format_backup(stack_backup[fd]);
	return (line);
}

static char	*ft_read_fd(int fd, char *stack_backup, char *heap_buffer)
{
	int		bytes_read;
	char	*tmp_buffer;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, heap_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(heap_buffer);
			return (NULL);
		}
		if (!stack_backup)
			stack_backup = ft_strdup("");
		tmp_buffer = stack_backup;
		heap_buffer[bytes_read] = '\0';
		stack_backup = ft_strjoin(tmp_buffer, heap_buffer);
		free(tmp_buffer);
		if (ft_strchr(heap_buffer, '\n'))
			break ;
	}
	free (heap_buffer);
	return (stack_backup);
}

static char	*ft_format_line(char *line)
{
	int		count;
	char	*new_line;

	count = 0;
	while (line[count] && line[count] != '\n')
		count++;
	new_line = (char *) malloc(sizeof(char) * count + 2);
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, line, count + 2);
	if (*new_line)
		return (new_line);
	free(new_line);
	return (NULL);
}

static char	*ft_format_backup(char *line)
{
	int		count;
	char	*new_backup;
	size_t	line_size;

	count = 0;
	line_size = ft_strlen(line);
	while (line[count] && line[count] != '\n')
		count++;
	if (line[count] == '\0')
	{
		free(line);
		return (NULL);
	}
	new_backup = (char *) malloc(sizeof(char) * (line_size - count) + 1);
	if (!new_backup)
		return (NULL);
	ft_strlcpy(new_backup, line + count + 1, line_size - count + 1);
	free(line);
	return (new_backup);
}

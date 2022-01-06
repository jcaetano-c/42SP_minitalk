/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 06:50:41 by jcaetano          #+#    #+#             */
/*   Updated: 2021/10/08 15:05:15 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef MAX_FD
#  define MAX_FD 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

/**
 * @brief Read the text available on the file descriptor one line at a time
 * until the end of it.
 *
 * @param fd File descriptor to read from.
 * @return char* A line read from a file descriptor. NULL if error or not else
 * to read.
 */
char	*get_next_line(int fd);

#endif

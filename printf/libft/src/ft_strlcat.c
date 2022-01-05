/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:39:31 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/02 19:40:38 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = 0;
	if (dest_len > size || size == 0)
		return (src_len + size);
	while ((src[i]) && i + 1 < (size - dest_len))
	{
		dest[i + dest_len] = src[i];
		++i;
	}
	if (dest_len != size)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:44:35 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/08 15:39:55 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	needle_length;
	char	*ptr_haystack;

	i = 0;
	needle_length = ft_strlen(needle);
	ptr_haystack = (char *)haystack;
	if (!(*needle))
		return ((char *)haystack);
	while (*ptr_haystack && (i < n))
	{
		if ((ft_strncmp(ptr_haystack, needle, needle_length) == 0)
			&& (i + needle_length <= n))
			return ((char *)ptr_haystack);
		ptr_haystack++;
		i++;
	}
	return (NULL);
}

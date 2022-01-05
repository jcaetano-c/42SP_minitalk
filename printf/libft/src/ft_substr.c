/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:11:41 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/09 15:46:13 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	s_len -= start;
	if (s_len < len || len > INT_MAX)
		len = s_len;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}

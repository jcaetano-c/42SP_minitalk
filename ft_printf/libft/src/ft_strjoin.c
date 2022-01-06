/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:47:25 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/09 16:12:42 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	new_str_len;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str_len = s1_len + s2_len;
	new_str = (char *)malloc(sizeof(char) * new_str_len + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, s1_len + 1);
	ft_strlcat(&new_str[s1_len], s2, s2_len + 1);
	return (new_str);
}

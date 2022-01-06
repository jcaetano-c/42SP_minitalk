/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:29:31 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/09 12:01:29 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_string;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	new_string = (char *)malloc(s_len);
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s, s_len);
	return (new_string);
}

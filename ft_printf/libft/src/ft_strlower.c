/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:01:21 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/22 19:05:53 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlower(char *str)
{
	int		i;
	char	*new_str;
	size_t	new_str_len;

	new_str_len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * new_str_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (str[++i])
			new_str[i] = ft_tolower(str[i]);
	return (new_str);
}

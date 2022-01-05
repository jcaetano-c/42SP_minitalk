/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:26:02 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/08 10:42:37 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr( const char *str, int c )
{
	const char	*s;

	s = str;
	while (*s != (char) c)
		if (*s++ == 0)
			return (NULL);
	return ((char *)s);
}

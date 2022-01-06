/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:06:46 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/10 06:35:22 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*s;

	s = str + (ft_strlen(str));
	while (s >= str)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:58:28 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/13 09:50:34 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)str;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
	}
	return (NULL);
}

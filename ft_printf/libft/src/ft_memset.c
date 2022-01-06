/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:26:49 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/02 14:29:09 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((char *)dest)[i] = (unsigned char) c;
		i++;
	}
	return (dest);
}

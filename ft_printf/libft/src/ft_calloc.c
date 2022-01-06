/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:30:42 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/08 16:52:57 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	size_t	*slot;

	total_size = nmemb * size;
	slot = (size_t *)malloc(total_size);
	if (!slot || (total_size > INT_MAX))
		return (NULL);
	ft_memset(slot, 0, total_size);
	return ((void *)slot);
}

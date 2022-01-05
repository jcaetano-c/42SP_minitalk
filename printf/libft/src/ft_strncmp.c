/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:21:30 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/08 15:43:55 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != 0 || s2[i] != 0) && (s1[i] == s2[i]) && (i < n - 1))
		i++;
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:10:15 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/07 12:04:28 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static size_t	ft_nb_count(int nb)
{
	size_t	size;

	size = 1;
	nb /= 10;
	while (nb)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static char	*ft_convert_nbr(char *s, size_t size, unsigned int nb)
{
	s[size] = '\0';
	while (size--)
	{
		s[size] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}

void	ft_put_pid(int n)
{
	char			*s;
	size_t			size;
	unsigned int	negative;

	size = ft_nb_count(n);
	s = (char *)malloc(sizeof(char) * size + 1);
	if (!s)
		return ;
	s = ft_convert_nbr(s, size, (unsigned int)n);
	write(1, s, size);
	free(s);
}

size_t	ft_strlen(const char *str)
{
	size_t		size;
	const char	*s;

	size = 0;
	s = str;
	while (*s++)
		size++;
	return (size);
}

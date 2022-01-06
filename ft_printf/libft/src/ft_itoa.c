/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:14:42 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/13 13:30:48 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nb_count(int n);
static char		*ft_convert_nbr(char *s, size_t size, unsigned int nb,
					int negative);

char	*ft_itoa(int n)
{
	char			*s;
	size_t			size;
	unsigned int	negative;

	size = ft_nb_count(n);
	negative = 0;
	s = (char *)malloc(sizeof(char) * size + 1);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	return (ft_convert_nbr(s, size, (unsigned int)n, negative));
}

static size_t	ft_nb_count(int nb)
{
	size_t	size;

	size = 1;
	if (nb < 0)
		size++;
	nb /= 10;
	while (nb)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static char	*ft_convert_nbr(char *s, size_t size, unsigned int nb, int negative)
{
	s[size] = '\0';
	while (size--)
	{
		s[size] = (nb % 10) + '0';
		nb /= 10;
	}
	if (negative)
		s[0] = '-';
	return (s);
}

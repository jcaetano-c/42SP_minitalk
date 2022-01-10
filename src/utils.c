/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:10:15 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/10 08:04:09 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	return (res);
}

char	*ft_itoa(int n)
{
	char			*s;
	size_t			size;
	int				n_2;

	n_2 = n;
	size = 1;
	n_2 /= 10;
	while (n_2)
	{
		n_2 /= 10;
		size++;
	}
	s = (char *)malloc(sizeof(char) * size + 1);
	if (!s)
		return (NULL);
	s[size] = '\0';
	while (size--)
	{
		s[size] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

void	ft_put_pid(int pid)
{
	char	*str;

	str = ft_itoa(pid);
	write(1, str, ft_strlen(str));
	write(1, "\n", 2);
	free(str);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 08:24:33 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/03 09:01:58 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	ft_signal(char c);

double	ft_atof(const char *str)
{
	double	res;
	int		signal;
	int		size;

	signal = 1;
	res = 0;
	size = 0;
	while (ft_isspace(*str))
		str++;
	signal = ft_signal(*str);
	if (signal == 1 || signal == -1)
		str++;
	while (ft_isdigit(*str) || *str == '.')
	{
		if (*str != '.' && *str != '0')
		{
			res = (res * 10) + (*str - 48);
			size++;
		}
		++str;
	}
	if (*str)
		return (0);
	res = (res * signal) / pow(10, size);
	return (res);
}

static	int	ft_signal(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (1);
}

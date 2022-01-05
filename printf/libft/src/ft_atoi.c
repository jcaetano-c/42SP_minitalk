/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:44:50 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/03 08:50:21 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_signal(char c);

int	ft_atoi(const char *str)
{
	int	res;
	int	signal;

	signal = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	signal = ft_signal(*str);
	if (signal == 1 || signal == -1)
		str++;
	else if (*str == 43)
		str++;
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - 48);
	return (res * signal);
}

static	int	ft_signal(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

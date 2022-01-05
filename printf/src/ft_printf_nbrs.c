/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:47:39 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/05 05:33:08 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		size += ft_putchar('-');
		if (n == -2147483648)
		{
			size += ft_putchar('2');
			n = -147483648;
		}
		n = -n;
	}
	if (n >= 10)
		size += ft_putnbr(n / 10);
	size += ft_putchar(n % 10 + '0');
	return (size);
}

int	ft_unsigned(unsigned int n)
{
	size_t	size;

	size = 0;
	if (!(n > 0) && !(n * -1 >= UINT_MAX))
		n = (n * -1) - 1;
	if (n >= 10)
		size += ft_unsigned(n / 10);
	size += ft_putchar(n % 10 + '0');
	return (size);
}

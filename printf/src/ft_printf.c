/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 09:51:56 by jcaetano          #+#    #+#             */
/*   Updated: 2021/11/01 14:42:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_switch(char *c, va_list ap);

int	ft_printf(const char *format, ...)
{
	char			*str;
	unsigned int	count;
	va_list			ap;

	va_start(ap, format);
	if (!format)
		va_end(ap);
	str = (char *)format;
	count = 0;
	while (*str)
	{
		while (*str != '%' && *str)
		{
			count += ft_putchar(*str);
			str++;
		}
		if (!*str)
			break ;
		str++;
		count += ft_switch(str, ap);
		str ++;
	}
	va_end(ap);
	return (count);
}

int	ft_switch(char *c, va_list ap)
{
	if (*c == '%')
		return (ft_putchar('%'));
	if (*c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (*c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (*c == 'd' || *c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (*c == 'u')
		return (ft_unsigned(va_arg(ap, unsigned int)));
	if (*c == 'x')
		return (ft_hex_digit(va_arg(ap, unsigned int), 1));
	if (*c == 'X')
		return (ft_hex_digit(va_arg(ap, unsigned int), 0));
	if (*c == 'p')
		return (ft_get_ptr(va_arg(ap, void *)));
	return (0);
}

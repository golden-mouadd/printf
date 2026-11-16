/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouabous <mouabous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 08:13:49 by mouabous          #+#    #+#             */
/*   Updated: 2026/11/11 15:39:08 by mouabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_specifier(char c, va_list arg)
{
	int	r1;
	int	r2;

	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstrr(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(arg, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'u')
		return (ft_putposnbr(va_arg(arg, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(arg, unsigned int), c));
	if (c == '%')
		return (ft_putchar('%'));
	r1 = ft_putchar('%');
	if (r1 == -1)
		return (-1);
	r2 = ft_putchar(c);
	if (r2 == -1)
		return (-1);
	return (r1 + r2);
}

static int	ft_clean(va_list arg)
{
	va_end(arg);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		l;
	int		count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && !format[i + 1])
			return (ft_clean(arg));
		if (format[i] == '%')
			l = ft_specifier(format[++i], arg);
		else
			l = ft_putchar(format[i]);
		if (l == -1)
			return (ft_clean(arg));
		count += l;
		i++;
	}
	va_end(arg);
	return (count);
}

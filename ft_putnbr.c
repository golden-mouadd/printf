/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouabous <mouabous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:51:06 by mouabous          #+#    #+#             */
/*   Updated: 2026/11/04 15:39:49 by mouabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putbr(long n)
{
	int	count;
	int	l;

	l = 0;
	count = 0;
	if (n < 0)
	{
		l = ft_putchar('-');
		if (l == -1)
			return (-1);
		count += l;
		n = -n;
	}
	if (n > 9)
	{
		l = ft_putbr(n / 10);
		if (l == -1)
			return (-1);
		count += l;
	}
	l = ft_putchar((n % 10) + '0');
	if (l == -1)
		return (-1);
	count += l;
	return (count);
}

int	ft_putnbr(int nb)
{
	return (ft_putbr(nb));
}

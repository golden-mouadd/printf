/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putposnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouabous <mouabous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:23:01 by mouabous          #+#    #+#             */
/*   Updated: 2026/11/04 15:39:51 by mouabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putposnbr(unsigned long nb)
{
	int	count;
	int	l;

	l = 0;
	count = 0;
	if (nb >= 10)
	{
		l = ft_putposnbr(nb / 10);
		if (l == -1)
			return (-1);
		count += l;
	}
	l = ft_putchar((nb % 10) + '0');
	if (l == -1)
		return (-1);
	count += l;
	return (count);
}

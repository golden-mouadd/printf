/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouabous <mouabous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 08:13:34 by mouabous          #+#    #+#             */
/*   Updated: 2026/11/14 16:20:57 by mouabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(uintptr_t nb, char format)
{
	char	*base;
	int		count;
	int		l;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		l = ft_puthex(nb / 16, format);
		if (l == -1)
			return (-1);
		count += l;
	}
	l = write(1, &base[nb % 16], 1);
	if (l == -1)
		return (-1);
	count += l;
	return (count);
}

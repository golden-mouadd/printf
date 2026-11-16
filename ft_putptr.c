/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouabous <mouabous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:48:18 by mouabous          #+#    #+#             */
/*   Updated: 2026/11/12 08:27:02 by mouabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	nb;
	int				count;
	int				temp;

	if (!ptr)
		return (ft_putstrr("(nil)"));
	nb = (uintptr_t)ptr;
	count = 0;
	temp = write(1, "0x", 2);
	if (temp == -1)
		return (-1);
	count += temp;
	temp = ft_puthex(nb, 'x');
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

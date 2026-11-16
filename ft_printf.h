/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouabous <mouabous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:18:02 by mouabous          #+#    #+#             */
/*   Updated: 2026/11/14 15:22:32 by mouabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_puthex(uintptr_t nb, char format);
int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putnbr(int nb);
int	ft_putstrr(char *str);
int	ft_putptr(void *ptr);
int	ft_putposnbr(unsigned long nb);

#endif

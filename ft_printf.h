/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:31:21 by zamgar            #+#    #+#             */
/*   Updated: 2024/06/12 18:32:52 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_unsigned_putnbr(unsigned int n);
int	ft_dec_into_hex(long n, int b);
int	ft_putptr(unsigned long long adress);
int	get_next_arg(va_list *ap, char c);
int	ft_printf(const char *str, ...);

#endif

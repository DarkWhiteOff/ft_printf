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

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int					ft_printf(const char *str, ...);
int					get_next_arg(va_list *ap, char c);
int					ft_dec_into_hex(unsigned int n, int b);
int					ft_itoa2(int n);
char				*ft_itoa(int n);
char				*ft_min(char *str);
int					ft_count(int n);
int					ft_unsigned_itoa2(unsigned int n);
char				*ft_unsigned_itoa(unsigned int n);
int					ft_unsigned_count(unsigned int n);
int					ft_putptr(unsigned long long adress);
int					ft_putstr(char *str);
int					ft_putchar(char c);
size_t				ft_strlen(const char *s);

#endif

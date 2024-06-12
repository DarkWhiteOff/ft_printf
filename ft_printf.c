/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:48:28 by zamgar            #+#    #+#             */
/*   Updated: 2024/06/12 18:33:04 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	/*if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}*/
	/*if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}*/
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

//n % 16 - 10 + 'a';

void	ft_dec_into_hex(int n, int b)
{
	int	div;
	int	mod;
	char	*string;

	if (b == 1)
		string = "0123456789ABCDEF";
	if (b == 0)
		string = "0123456789abcdef";
	div = n / 16;
	mod = n % 16;

	ft_putchar_fd(string[div], 1);
	ft_putchar_fd(string[mod], 1);
}

/*void	ft_putptr(void *adress)
{
	int	i;
	char	*str;

	i = 0;
	ft_putstr_fd("0x", 1);
	ft_dec_into_hex(&adress, 0);
	//printf("%p", adress);
}*/

void	get_next_arg(va_list *ap, char c)
{
	if (c == 'c')
		ft_putchar_fd((va_arg(*ap, int)), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(*ap, char *), 1);
//	else if (c == 'p')
//		ft_putptr(va_arg(*ap, void*));
	else if (c == 'd')
		ft_putnbr_fd(va_arg(*ap, int), 1);
	else if (c == 'i')
		ft_putnbr_fd(va_arg(*ap, int), 1);
	else if (c == 'u')
		ft_unsigned_putnbr_fd(va_arg(*ap, unsigned int), 1);	
	else if (c == 'x')
		ft_dec_into_hex(va_arg(*ap, int), 0);
	else if (c == 'X')
		ft_dec_into_hex(va_arg(*ap, int), 1);
	else if (c == '%')
		ft_putchar_fd(c, 1);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list ap;

	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			get_next_arg(&ap, str[i + 1]);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i - 1);
}

/*int	main()
{
	int	a = 45;
	int	b = 45;
	int	*x = &a;
	int	*y = &b;

	printf("x : %p\ny : %p\n\n", (void *)x, (void *)y);
	ft_printf("ceci est l adresse de x : %p\n", (void *)x);
	return (0);
}*/

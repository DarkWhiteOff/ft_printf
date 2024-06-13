/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:48:28 by zamgar            #+#    #+#             */
/*   Updated: 2024/06/13 17:37:42 by zamgar           ###   ########.fr       */
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
	if (str == NULL)
	{
		ft_putchar_fd('(', 1);
		ft_putchar_fd('n', 1);
		ft_putchar_fd('u', 1);
		ft_putchar_fd('l', 1);
		ft_putchar_fd('l', 1);
		ft_putchar_fd(')', 1);
		return ;
	}
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
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_dec_into_hex(int n, int b)
{
	int	temp;
	char	*string;
	char	*array;
	int	i;
	int	count;

	i = 0;
	count = 0;
	temp = n;
	if (b == 1)
		string = "0123456789ABCDEF";
	if (b == 0)
		string = "0123456789abcdef";
	while (temp >= 1)
	{
		temp = temp / 16;
		count++;
	}
	array = (char *)malloc(sizeof(char) * count + 1);
	if (array == NULL)
		return ;
	while (n > 0)
	{
		temp = n % 16;
		array[i] = string[temp];
		i++;
		n = n / 16;
	}
	array[i] = '\0';
	i = i - 1;
	while (i >= 0)
	{
		ft_putchar_fd(array[i], 1);
			i--;
	}
	free(array);
}

void	ft_putptr(unsigned long long adress)
{
	unsigned long long	temp;
	char	*string;
	char	*array;
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	temp = adress;
	string = "0123456789abcdef";
	ft_putstr_fd("0x", 1);
	while (temp >= 1)
	{
		temp = temp / 16;
		count++;
	}
	array = (char *)malloc(sizeof(char) * count + 1);
	if (array == NULL)
		return ;
	while (adress > 0)
	{
		temp = adress % 16;
		array[i] = string[temp];
		i++;
		adress = adress / 16;
	}
	array[i] = '\0';
	i = i - 1;
	while (i >= 0)
	{
		ft_putchar_fd(array[i], 1);
			i--;
	}
	free(array);
}

int	get_next_arg(va_list *ap, char c)
{
	if (c == 'c')
		ft_putchar_fd((va_arg(*ap, int)), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(*ap, char *), 1);
	else if (c == 'p')
		ft_putptr(va_arg(*ap, unsigned long long));
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
	return (i - 1); // probleme ne return pas la bonne taille
}

int	main()
{
	int	a = 16;
	int	*x = &a;

	printf("vrai printf :\n");
	printf(" %x ", a);
	printf("\n");
	printf("my printf :\n");
	ft_printf(" %x ", a);
	printf("\n");
	return (0);
}

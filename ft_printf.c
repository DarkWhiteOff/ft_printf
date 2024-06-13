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

	i = 0;
	temp = 0;
	string = (char *)malloc(sizeof(char) * 17);
	array = (char *)malloc(sizeof(char) * 100);
	if (string == NULL || array == NULL)
		return ;
	string = "0123456789abcdef";
	temp = 100;
	while(i < 100)
	{
		array[i] = '\0';
		i++;
	}
	i = 0;
	if (b == 1)
		string = "0123456789ABCDEF";
	if (b == 0)
		string = "0123456789abcdef";
	while (n > 0)
	{
		temp = n % 16;
		array[i] = string[temp];
		i++;
		n = n / 16;
	}
	ft_putstr_fd(array, 1);
	free(string);
	free(array);
}

void	ft_long_dec_into_hex(unsigned long long n)
{
	unsigned long long	temp;
	char	*string;
	char	*array;
	int	i;

	i = 0;
	temp = 0;
	string = (char *)malloc(sizeof(char) * 17);
	array = (char *)malloc(sizeof(char) * 100);
	if (string == NULL || array == NULL)
		return ;
	string = "0123456789abcdef";
	temp = 100;
	while(i < 100)
	{
		array[i] = '\0';
		i++;
	}
	i = 0;
	while (n > 0)
	{
		temp = n % 16;
		array[i] = string[temp];
		i++;
		n = n / 16;
	}
	ft_putstr_fd(array, 1);
	free(string);
	free(array);
}

void	ft_putptr(unsigned long long adress)
{
	ft_putstr_fd("0x", 1);
	ft_long_dec_into_hex(adress);
}

void	get_next_arg(va_list *ap, char c)
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

/*int	main()
{
	//printf("vrai printf :\n");
	//printf(" NULL %s NULL ", (char *)NULL);
	//printf("\n");
	printf("%d", printf("%s%s%s", "test", "test", "test"));
	//printf("my printf :\n");
	//ft_printf("%s", "");
	printf("\n");
	return (0);
}*/

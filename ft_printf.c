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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_min(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_count(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
		return (ft_min(str));
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[i] = '\0';
	while (n >= 10)
	{
		str[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[i - 1] = n + '0';
	return (str);
}

static int	ft_unsigned_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	int		i;
	char	*str;

	i = ft_unsigned_count(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[i] = '\0';
	while (n >= 10)
	{
		str[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[i - 1] = n + '0';
	return (str);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_itoa2(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(n);
	i = ft_strlen((const char *)str);
	ft_putstr(str);
	free(str);
	return (i);
}

int	ft_unsigned_itoa2(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_unsigned_itoa(n);
	i = ft_strlen((const char *)str);
	ft_putstr(str);
	free(str);
	return (i);
}

int	ft_dec_into_hex(unsigned int n, int b)
{
	unsigned int	temp;
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
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (temp >= 1)
	{
		temp = temp / 16;
		count++;
	}
	array = (char *)malloc(sizeof(char) * count + 1);
	if (array == NULL)
		return (0);
	while (n > 0)
	{
		temp = n % 16;
		array[i] = string[temp];
		i++;
		n = n / 16;
	}
	array[i] = '\0';
	temp = i;
	i = i - 1;
	while (i >= 0)
	{
		ft_putchar(array[i]);
			i--;
	}
	free(array);
	return (temp);
}

int	ft_putptr(unsigned long long adress)
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
	if (adress == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	while (temp >= 1)
	{
		temp = temp / 16;
		count++;
	}
	array = (char *)malloc(sizeof(char) * count + 1);
	if (array == NULL)
		return (0);
	while (adress > 0)
	{
		temp = adress % 16;
		array[i] = string[temp];
		i++;
		adress = adress / 16;
	}
	array[i] = '\0';
	temp = i;
	i = i - 1;
	while (i >= 0)
	{
		ft_putchar(array[i]);
			i--;
	}
	free(array);
	return (temp + 2);
}

int	get_next_arg(va_list *ap, char c)
{
	int	printed_lenght;

	printed_lenght = 0;
	if (c == 'c')
		printed_lenght += ft_putchar((va_arg(*ap, int)));
	else if (c == 's')
		printed_lenght += ft_putstr(va_arg(*ap, char *));
	else if (c == 'p')
		printed_lenght += ft_putptr(va_arg(*ap, unsigned long long));
	else if (c == 'd')
		printed_lenght += ft_itoa2(va_arg(*ap, int));
	else if (c == 'i')
		printed_lenght += ft_itoa2(va_arg(*ap, int));
	else if (c == 'u')
		printed_lenght += ft_unsigned_itoa2(va_arg(*ap, unsigned int));	
	else if (c == 'x')
		printed_lenght += ft_dec_into_hex(va_arg(*ap, unsigned int), 0);
	else if (c == 'X')
		printed_lenght += ft_dec_into_hex(va_arg(*ap, unsigned int), 1);
	else if (c == '%')
		printed_lenght += ft_putchar(c);
	return (printed_lenght);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	count;
	va_list ap;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += get_next_arg(&ap, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	return (count);
}

/*int	main()
{
	int	a = 0;
	int	*x = &a;
	char	*str = "cacabonjourjesuiscaca";
	char	*str2 = "ouieneffet";

	printf("vrai printf :\n");
	printf("%d", printf(" %d ", 10));
	printf("\n");
	printf("my printf :\n");
	ft_printf("%d", ft_printf(" %d ", 10));
	printf("\n");
	return (0);
}*/

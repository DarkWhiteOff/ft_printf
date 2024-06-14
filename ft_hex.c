#include "ft_printf.h"

int	ft_dec_into_hex(unsigned int n, int b)
{
	unsigned int	temp;
	char			*string;
	char			*array;
	int				i;
	int				count;

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

#include "ft_printf.h"

int	ft_putptr(unsigned long long adress)
{
	unsigned long long	temp;
	char				*string;
	char				*array;
	int					i;
	int					count;

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

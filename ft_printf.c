#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list ap;

	i = 0;
	va_start(ap, str);
	while (str[i] ! = '\0')
	{
		if (str[i]

		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main()
{
	char	*str = "Ziggy";
	ft_printf("Bonjour je m'appelle %d", str);
	return (0);
}

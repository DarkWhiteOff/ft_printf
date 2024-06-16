#include "ft_printf.h"
#include <stdio.h>

int     main(void)
{
	int	a = 45;
	int	*x = &a;
	
        printf("vrai printf :\n");
        printf("%p", (void *)x);
        printf("\n");
        printf("my printf :\n");
        ft_printf("%p", (void *)x);
        printf("\n");
        return (0);
}

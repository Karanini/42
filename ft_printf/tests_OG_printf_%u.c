#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	printf(" %u ", -1);
	printf(" %u ", -9);
	printf(" %u ", -10);
	printf(" %u ", -11);
	printf(" %u ", -2147483647);
	printf("\n");
	fflush(stdout);

	ft_printf(" %u ", -1);
	ft_printf(" %u ", -9);
	ft_printf(" %u ", -10);
	ft_printf(" %u ", -11);
	ft_printf("\n");
	return (0);
}

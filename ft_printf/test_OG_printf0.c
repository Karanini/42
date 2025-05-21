#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int ret = printf(0);
	printf("%d", ret);
	ret = ft_printf(0);
	printf("%d", ret);
	return(0);
}

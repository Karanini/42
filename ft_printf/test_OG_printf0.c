#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int ret = printf("");
	printf("%d", ret);
	ret = ft_printf("");
	printf("%d", ret);
	return(0);
}

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char tab[] = {1, 2, 3, 4};

	char *res = ft_memmove(tab + 1, tab, 2);
	for (int i = 0; i < 4; i++)
		printf("%d", res[i]);
	return (0);
}

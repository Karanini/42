#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char **tab = ft_split("  tripouille  42  ", ' ');
	printf("tab[0] : %s", tab[0]);
	printf("tab[1] : %s", tab[1]);
	return (0);
}

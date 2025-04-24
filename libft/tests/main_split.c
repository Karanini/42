#include "libft.h"
#include <stdio.h>

void freeTab(char **tab)
{
	for (int i = 0; tab[i] != NULL; ++i)
		free(tab[i]);
	free(tab);
}

int	main(void)
{
	char **tab = ft_split("  tripouille  42  ", ' ');
	printf("tab[0]==%s\n", tab[0]);
	printf("tab[1]==%s\n", tab[1]);
	freeTab(tab);
	char **tab1 = ft_split("tripouille", 0);
	printf("tab[0]==%s\n", tab[0]);
	freeTab(tab1);
	return (0);
}

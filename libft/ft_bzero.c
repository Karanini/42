#include <stdio.h>

void ft_bzero(void *s, size_t n)
{
	unsigned char *ptr;
	size_t	i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

int	main(void)
{
	int tab[] = {2, 32, 42};
	int i = 0;
	ft_bzero(tab, sizeof(int) * 3);
	while (i < 3)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}

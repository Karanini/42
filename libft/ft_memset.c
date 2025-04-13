#include <stddef.h>
#include <stdio.h>
#include <string.h>

void *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char *ptr;

    ptr = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        ptr[i] = (unsigned char)c;
        i++;
    }
    return s;
}

int main(void)
{
	int	i;
	int	len;
	i = 0;
	int tab[] = {2, 3, 4};
	len = sizeof(int) * 3;
	ft_memset(tab, 0, len);
	while (i < 3)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	printf("len : %d", len);
	return (0);
}

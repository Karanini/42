
#include <stddef.h>

void    *ft_memset(void *s, int c, size_t n)
{

    size_t  i;
    unsigned char *s1;

    i = 0;
    s1 = (unsigned char *)s;

    while (i < n)
        s1[i++] = (unsigned char)c;
    return (s);
}
#include <stdio.h>

int main(void)
{
    int c = 1;
    size_t n = 8;
    int tab[3] = {0, 1, 2};
    ft_memset(tab, c, n);
    for (int i = 0; i < 3; i++)
        printf("%d\n", tab[i]);
    return (0);
}
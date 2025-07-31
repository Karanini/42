#include <stdio.h>
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

int main(void)
{
    int tab[3] = {0, 1, 2};
    
    printf("Before memset:\n");
    printf("tab[0] = %d (0x%08x)\n", tab[0], tab[0]);
    printf("tab[1] = %d (0x%08x)\n", tab[1], tab[1]);
    printf("tab[2] = %d (0x%08x)\n", tab[2], tab[2]);
    
    // Let's look at the bytes
    unsigned char *bytes = (unsigned char *)tab;
    printf("\nByte by byte before memset:\n");
    for (int i = 0; i < 12; i++) {
        printf("byte[%d] = %d (0x%02x)\n", i, bytes[i], bytes[i]);
    }
    
    // Apply memset
    ft_memset(tab, 1, 8);
    
    printf("\nAfter memset(tab, 1, 8):\n");
    printf("tab[0] = %d (0x%08x)\n", tab[0], tab[0]);
    printf("tab[1] = %d (0x%08x)\n", tab[1], tab[1]);
    printf("tab[2] = %d (0x%08x)\n", tab[2], tab[2]);
    
    printf("\nByte by byte after memset:\n");
    for (int i = 0; i < 12; i++) {
        printf("byte[%d] = %d (0x%02x)\n", i, bytes[i], bytes[i]);
    }
    
    // Show the calculation
    printf("\nCalculation for 16843009:\n");
    printf("1×1        = %d\n", 1);
    printf("1×256      = %d\n", 256);
    printf("1×65536    = %d\n", 65536);
    printf("1×16777216 = %d\n", 16777216);
    printf("Total      = %d\n", 1 + 256 + 65536 + 16777216);
    
    return (0);
}

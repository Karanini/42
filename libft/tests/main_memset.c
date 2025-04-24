#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void) {
    char buf1[10] = "abcdefghi";
    char buf2[10] = "abcdefghi";
    ft_memset(buf1, 'x', 5);
    memset(buf2, 'x', 5);
    printf("ft_memset: %s\n", buf1);
    printf("memset:    %s\n", buf2);
    return 0;
}

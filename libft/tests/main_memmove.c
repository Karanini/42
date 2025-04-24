#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void) {
    char str1[20] = "abcdef";
    char str2[20] = "abcdef";
    ft_memmove(str1+2, str1, 4);
    memmove(str2+2, str2, 4);
    printf("ft_memmove: %s\n", str1);
    printf("memmove:    %s\n", str2);
    return 0;
}

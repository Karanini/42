#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void) {
    char dst1[20] = "1234567890";
    char dst2[20] = "1234567890";
    ft_memcpy(dst1, "abc", 4);
    memcpy(dst2, "abc", 4);
    printf("ft_memcpy: %s\n", dst1);
    printf("memcpy:    %s\n", dst2);
    return 0;
}

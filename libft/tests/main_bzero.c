#include <stdio.h>
#include <strings.h>
#include "libft.h"

int main(void) {
    char s1[10] = "abcdefghi";
    char s2[10] = "abcdefghi";
    ft_bzero(s1, 5);
    bzero(s2, 5);
    for (int i = 0; i < 10; i++)
        printf("%d:%d\n", s1[i], s2[i]);
    return 0;
}

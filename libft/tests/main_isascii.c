#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main(void) {
    for (int c = -10; c <= 140; c++) {
        if (ft_isascii(c) != isascii(c)) {
            printf("Mismatch at %d: ft=%d std=%d\n", c, ft_isascii(c), isascii(c));
        }
    }
    return 0;
}

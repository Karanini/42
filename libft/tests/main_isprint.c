#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main(void) {
    for (int c = 0; c <= 127; c++) {
        if (ft_isprint(c) != isprint(c)) {
            printf("Mismatch at %d: ft=%d std=%d\n", c, ft_isprint(c), isprint(c));
        }
    }
    return 0;
}

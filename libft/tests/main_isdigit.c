#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main(void) {
    for (int c = 0; c <= 127; c++) {
        if (ft_isdigit(c) != isdigit(c)) {
            printf("Mismatch at '%c': ft=%d std=%d\n", c, ft_isdigit(c), isdigit(c));
        }
    }
    return 0;
}

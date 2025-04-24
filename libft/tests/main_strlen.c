#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void) {
    const char *tests[] = {"", "abc", "longer string", "string with \0 in middle\0rest", NULL};
    for (int i = 0; tests[i]; i++) {
        printf("ft_strlen("%s") = %zu\n", tests[i], ft_strlen(tests[i]));
    }
    return 0;
}

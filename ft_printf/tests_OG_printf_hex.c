#include <stdio.h>

int main(void)
{
    printf("%x\n", 323232);
    printf("%x\n", 2147483648);
    printf("%x\n", -32);
    printf("%x\n", 2147483650);
    printf("%x\n", 0);

    int *ptr;
    printf("%p\n", ptr);
}
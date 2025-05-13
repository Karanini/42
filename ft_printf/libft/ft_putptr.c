#include "libft.h"
#include <stdio.h>

static void    ft_putptr_recursive(uintptr_t ptr_int, int *bites_printed);

void    ft_putptr(void *ptr, int *bites_printed)
{
    uintptr_t   ptr_int;
    
    ft_putstr_fd("0x", 1);
    (*bites_printed) += 2;
    ptr_int = (uintptr_t)ptr;
    ft_putptr_recursive(ptr_int, bites_printed);
}

static void    ft_putptr_recursive(uintptr_t ptr_int, int *bites_printed)
{
    char    *base;

    base = "0123456789abcdef";
    if (ptr_int >= 16)
    {
        ft_putptr_recursive(ptr_int / 16, bites_printed);
        ft_putchar_fd(base[ptr_int % 16], 1);
    }
    else
        ft_putchar_fd(base[ptr_int], 1);
    (*bites_printed)++;
}

/*int main(void)
{
    int *a_nice_pointer;
    char    *a_wonderful_pointer;
    int     bites_printed;
    
    bites_printed = 0;
    printf("a_nice_pointer adress with ft_putptr : ");
    fflush(stdout);
    ft_putptr(a_nice_pointer, &bites_printed);
    ft_putchar_fd('\n', 1);
    printf("a_nice_pointer adress with OG printf : %p\n", a_nice_pointer);
    printf("bites_printed=%d", bites_printed);
    fflush(stdout);
    ft_putchar_fd('\n', 1);

    bites_printed = 0;
    printf("a_wonderful_pointer adress with ft_putptr : ");
    fflush(stdout);
    ft_putptr(a_wonderful_pointer, &bites_printed);
    ft_putchar_fd('\n', 1);
    printf("a_wonderful_pointer adress with OG printf : %p\n", a_wonderful_pointer);
    printf("bites_printed=%d", bites_printed);
    fflush(stdout);
    ft_putchar_fd('\n', 1);

    return (0);
}*/
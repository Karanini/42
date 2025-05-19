#include "libft.h"
# include <stdio.h>

void	ft_put_hexnbr(unsigned int nbr, char conv_specifier, int *bites_printed)
{
	char	*base;

	if (conv_specifier == 'x')
		base = "0123456789abcdef";
	if (conv_specifier == 'X')
		base = "0123456789ABCDEF";
	if (conv_specifier != 'x' && conv_specifier != 'X')
		return ;
	if (nbr >= 16)
	{
		ft_put_hexnbr(nbr / 16, conv_specifier, bites_printed);
		ft_putchar_fd(base[nbr % 16], 1);
	}
	else
		ft_putchar_fd(base[nbr], 1);
	// the ++ operator is executed before the * if we write *bites_printed++
	// so we need to put parenthesis around *bites_printed 
	(*bites_printed)++;
}
/*int	main(void)
{
	printf("\n");
	printf("ft_put_hexnbr tests");
	printf("\n");
	int	bites_printed = 0;

	printf("323232\n");
	ft_put_hexnbr(323232, 'x', &bites_printed);
	ft_putchar_fd('\n', 1);
	printf("bites printed=%d\n", bites_printed);

	bites_printed = 0;
	printf("2147483648\n");
	ft_put_hexnbr(2147483648, 'x', &bites_printed);
	ft_putchar_fd('\n', 1);
	printf("bites printed=%d\n", bites_printed);

	bites_printed = 0;
	printf("0\n");
	ft_put_hexnbr(0, 'x', &bites_printed);
	ft_putchar_fd('\n', 1);
	printf("bites printed=%d\n", bites_printed);

	bites_printed = 0;
	printf("15\n");
	ft_put_hexnbr(15, 'x', &bites_printed);
	ft_putchar_fd('\n', 1);
	printf("bites printed=%d\n", bites_printed);

	bites_printed = 0;
	printf("16\n");
	ft_put_hexnbr(16, 'x', &bites_printed);
	ft_putchar_fd('\n', 1);
	printf("bites printed=%d\n", bites_printed);

	return (0);
}*/

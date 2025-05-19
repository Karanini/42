#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int	printf_ret;
	char	*str;

	printf("OG printf error examples (return (-1))\n");
	printf("\n");
	printf("OG printf behavior if input is 'banana%%' (no specifier after the %%) \n");
	printf_ret = printf("banana%");
	printf("printf_ret=%d\n", printf_ret);

	printf("OG printf behavior if input is 'banana%%h' (wrong conversion specifier)\n");
	printf_ret = printf("banana%h");
	printf("printf_ret=%d\n", printf_ret);

	printf("OG printf behavior if input is NULL\n");
	printf_ret = printf(NULL);
	printf("printf_ret=%d\n", printf_ret);

	printf("\n");
	printf("undefined OG printf behaviors");
	printf("\n");
	printf("OG printf behavior if input is 'banana%%d' w/o the var precised\n");
	printf_ret = printf("banana%d\n");
	printf("printf_ret=%d\n", printf_ret);

	str = " and kiwi jaune";
	printf("OG printf behavior if input is 'banana%%d' with the wrong var (char *)\n");
	printf_ret = printf("banana%d\n", str);
	printf("printf_ret=%d\n", printf_ret);

	printf("\n");
	printf("correct OG printf behaviors");
	printf("\n");
	printf("OG printf behavior if input is 'banana%%s' with str (char *)\n");
	printf_ret = printf("banana%s\n", str);
	printf("printf_ret=%d\n", printf_ret);

	printf("OG printf behavior if input is \"\"\n");
	printf_ret = printf("");
	printf("printf_ret=%d\n", printf_ret);
	return (0);
}
/*int	main(void)
{
	//int	printf_ret;
	int	ft_printf_ret;
	const char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = "banana";
	printf("OG printf error examples (return (-1))\n");
	printf("\n");
	printf("OG printf behavior if input is 'banana%%' (no specifier after the %%) \n");
	printf_ret = printf("banana%");
	printf("printf_ret=%d\n", printf_ret);
	printf("ft_check_format returns %i\n", ft_check_format("%s%\n"));

	str2 = "banana";
	printf("OG printf behavior if input is 'banana%%h' (wrong conversion specifier)\n");
	printf_ret = printf("%s%h\n", str2);
	printf("printf_ret=%d\n", printf_ret);
	printf("ft_check_format returns %i\n", ft_check_format("%s%\n"));

	printf("OG printf behavior if input is NULL\n");
	printf_ret = printf(NULL);
	printf("printf_ret=%d\n", printf_ret);
	printf("ft_check_format returns %i\n", ft_check_format(NULL));

	printf("\n");
	printf("undefined OG printf behaviors");
	printf("\n");

	str3 = "banana";
	printf("OG printf behavior if input is 'banana%%d' w/o the 2nd arg (%%d) precised\n");
	printf_ret = printf("%s%d\n", str3);
	printf("printf_ret=%d\n", printf_ret);
	printf("ft_check_format returns %i\n", ft_check_format("%s%d\n"));

	str4 = " and kiwi jaune";
	printf("OG printf behavior if input is 'banana%%d' with the wrong 2nd arg (char * instead of int)\n");
	printf_ret = printf("%s%d\n", str3, str4);
	printf("printf_ret=%d\n", printf_ret);
	printf("ft_check_format returns %i\n", ft_check_format("%s%d\n"));

	printf("\n");
	printf("correct OG printf behaviors");
	printf("\n");

	printf("OG printf behavior if input is 'banana%%s' with correct 2nd arg str (char *)\n");
	printf_ret = printf("%s%s\n", str3, str4);
	printf("printf_ret=%d\n", printf_ret);
	printf("ft_check_format returns %i\n", ft_check_format("%s%s\n"));

	printf("OG printf behavior if input is \"\"\n");
	printf_ret = printf("");
	printf("printf_ret=%d\n", printf_ret);
	printf("ft_check_format returns %i\n", ft_check_format(""));

	printf("\n");
	printf("ft_printf tests");
	printf("\n");

	str1 = "stars";
	char c1 = '3';
	char c2 = '2';
	printf("test 1 : %%s and %%c\n");
	printf("expected output (OG printf) : %s are %c%c\n", str1, c1, c2);
	printf("ft_printf output : ");
	fflush(stdout);
	ft_printf_ret = ft_printf("%s are %c%c\n", str1, c1, c2);
	printf("ft_printf_ret=%d\n", ft_printf_ret);

	printf("\n");
	printf("test 2 : %%s and %%p\n");
	printf("expected output (OG printf) : str1 (%s) adress is %p !\n", str1, str1);
	printf("ft_printf output : ");
	fflush(stdout);
	ft_printf_ret = ft_printf("str1 (%s) adress is %p !\n", str1, str1);
	printf("ft_printf_ret=%d\n", ft_printf_ret);

	int nbr1 = 323232;
	int nbr2 = 0;

	printf("\n");
	printf("test 3a : %%d, %%%% and %%i\n");
	printf("expected output (OG printf) : nbr1 %%d=%d, nbr1 %%i=%i\n", nbr1, nbr1);
	printf("ft_printf output : ");
	fflush(stdout);
	ft_printf_ret = ft_printf("nbr1 %%d=%d, nbr1 %%i=%i\n", nbr1, nbr1);
	printf("ft_printf_ret=%d\n", ft_printf_ret);

	printf("\n");
	printf("test 3b : %%d, %%%% and %%i\n");
	printf("expected output (OG printf) : nbr2 %%d=%d, nbr2 %%i=%i\n", nbr2, nbr2);
	printf("ft_printf output : ");
	fflush(stdout);
	ft_printf_ret = ft_printf("nbr2 %%d=%d, nbr2 %%i=%i\n", nbr2, nbr2);
	printf("ft_printf_ret=%d\n", ft_printf_ret);

	unsigned int nbr3 = 420;

	printf("\n");
	printf("test 4 : %%u\n");
	printf("expected output (OG printf) : nbr3 %%u=%u\n", nbr3);
	printf("ft_printf output : ");
	fflush(stdout);
	ft_printf_ret = ft_printf("nbr3 %%u=%u\n", nbr3);
	printf("ft_printf_ret=%d\n", ft_printf_ret);

	printf("\n");
	printf("test 5 : %%x\n");
	printf("expected output (OG printf) : nbr3 %%x=%x\n", nbr3);
	printf("ft_printf output : ");
	fflush(stdout);
	ft_printf_ret = ft_printf("nbr3 %%x=%x\n", nbr3);
	printf("ft_printf_ret=%d\n", ft_printf_ret);

	printf("\n");
	printf("test 6 : %%X\n");
	printf("expected output (OG printf) : nbr3 %%X=%X\n", nbr3);
	printf("ft_printf output : ");
	fflush(stdout);
	ft_printf_ret = ft_printf("nbr3 %%X=%X\n", nbr3);
	printf("ft_printf_ret=%d\n", ft_printf_ret);

	printf("\n");
	printf("ft_put_hexnbr tests");
	printf("\n");
	int	bites_printed = 0;
	ft_put_hexnbr(323232, 'x', &bites_printed);
	ft_put_hexnbr(2147483648, 'x', &bites_printed);
	ft_put_hexnbr(0, 'x', &bites_printed);
	ft_put_hexnbr(15, 'x', &bites_printed);
	ft_put_hexnbr(16, 'x', &bites_printed);
	return (0);
}*/

// int main(void)
// {
// 	ft_printf(" %u ", -1);
// 	ft_printf(" %u ", -9);
// 	ft_printf(" %u ", -10);
// 	ft_printf(" %u ", -11);
// 	ft_printf("\n");
// }

// int main(void)
// {
// 	printf(" %% ");
// 	printf(" %%%% ");
// 	printf(" %% %% %% ");
// 	printf(" %%  %%  %% ");
// 	printf(" %%   %%   %% ");
// 	printf("%%");
// 	printf("%% %%");
// 	printf("\n");
// 	fflush(stdout);

// 	int nb = ft_printf(" %% ");
// 	ft_printf(" %%%% ");
// 	ft_printf(" %% %% %% ");
// 	ft_printf(" %%  %%  %% ");
// 	ft_printf(" %%   %%   %% ");
// 	ft_printf("%%");
// 	ft_printf("%% %%");
// 	printf("\n");
// 	ft_printf("%d", nb);
// }

// int main(void)
// {
// 	printf(" NULL %s NULL ", NULL);
// 	printf("\n");
// 	ft_printf(" NULL %s NULL ", NULL);
// 	return (0);
// }

// int main(void)
// {
// 	printf(" %p %p ", 0, 0);
// 	printf("\n");
// 	ft_printf(" %p %p ", 0, 0);
// }

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

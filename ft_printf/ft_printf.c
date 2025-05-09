#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

//good printf examples : 
//printf("I love the %d and I mainly eat %s", 32, "yellow kiwis");
//printf(""); doesn't print ANYTHING and returns 0
//
//to clarify printf examples :
//printf("banana%d\n"); error but returns nb bites printed anyway
//printf("banana%d\n", str);error but returns nb bites printed anyway
//
//bad printf examples (don't print ANYTHING and return (-1)):
//printf(NULL)
//printf("banana%"); no conv. specifier after the %
//printf("banana%b"); b is not a conv. specifier 
//if printf("%s%h\n", "banana"); then "banana%h" is printed
//if printf("%s%h", "banana"); then nthng is printed and printf returns (-1)

static int	ft_check_format(const char *format); 

int	ft_printf(const char *format, ...)
{
	int	bites_printed;
	va_list	args;
	size_t	i;
	const char	*s;

	if (ft_check_format(format) == -1)
		return (-1);
	if (ft_check_format(format) == 0)
		return (0);
	va_start(args, format);
//if no var arg then print format directly and return its length
//not possible to check if no args -> skip this part ?
//if no var arg but some conv. specifiers are present it can be 
//problematic
/*	if (args[0] == NULL)
	{
		ft_putstr_fd(format, 1);
		va_end(args);
		return (ft_strlen(format));
	}*/
	bites_printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			i++;
			bites_printed++;
		}
		if (format[i] == '%' && format[i + 1])
		{
//call functions instead of treating everything here
//group by similar types ? eg 
//c and s together, 
//i, d and u 
//x and X
//p
// norm : 5 functions max per file
			if (format[i + 1] == 'c')
			{
				ft_putchar_fd((unsigned char)va_arg(args, int), 1);
				bites_printed++;
			}
			if (format[i + 1] == 's')
			{
				s = va_arg(args, const char *),
				ft_putstr_fd((char *)s, 1);
				bites_printed+=ft_strlen(s);
			}
			i = i + 2;
		}
	}
	return (bites_printed);
}

static int	ft_check_format(const char *format)
{
	size_t	i;
	char	*specifiers_set;

	i = 0;
	specifiers_set = "cspdiuxX%";
	if (format == NULL)
		return (-1);
	if (format[0] == '\0')
		return (0);
	while(format[i])
	{
//check if we need to take into acbites_printed those error cases :
		if (format[i] == '%' && (!format[i + 1] ||
			!ft_strchr(specifiers_set, format[i + 1])))
			return (-1);
		i++;
	}
	return (1);
}
int	main(void)
{
	//int	printf_ret;
	int	ft_printf_ret;
	const char	*str1;
	/*char	*str2;
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
	printf("ft_check_format returns %i\n", ft_check_format(""));*/
	
	printf("\n");
	printf("ft_printf tests");
	printf("\n");

	str1 = "stars";
	int c1 = '3';
	int c2 = '2';
	printf("test 1\n");
	printf("expected output (OG printf) : %s are %c%c\n", str1, c1, c2);
	ft_printf_ret = ft_printf("%s are %c%c\n", str1, c1, c2);
	printf("ft_printf_ret=%d\n", ft_printf_ret);

	return (0);
}

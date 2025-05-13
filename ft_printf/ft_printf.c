#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

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
//if we have a char to print or if we have '%%'
		if (format[i] != '%' || (format[i] == '%' &&
			format[i + 1] == '%'))
		{
			ft_putchar_fd(format[i], 1);
//if we have '%%' we print the first % then skip the next
			if (format[i + 1] == '%')
				i += 2;
			else
				i++;
			bites_printed++;
		}
		if (format[i] == '%' && format[i + 1])
		{
//call functions instead of treating everything here
//Idea A :group by similar types ? eg
//c and s together,
//i, d and u
//x and X
//p
// Idea B :
// one func to treat the conv. specifier ie all the following ifs
// one func ft_putptr
// one func ft_put_hexnbr
// norm : 5 functions max per file
			if (format[i + 1] == 'c')
			{
				ft_putchar_fd((unsigned char)va_arg(args, int), 1);
				// modify putchar and putstr to count the bites printed ?
				bites_printed++;
			}
			if (format[i + 1] == 's')
			{
				s = va_arg(args, const char *),
				ft_putstr_fd((char *)s, 1);
				bites_printed += ft_strlen(s);
			}
			if (format[i + 1] == 'p')
				ft_putptr(va_arg(args, void *), &bites_printed);
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				ft_putnbr_fd(va_arg(args, int), 1);
			//modify putnbr to return the number's length to be able to
			//add it to bites_printed?
			//is it allowed to modify the functions from libft ?
			}
			if (format[i + 1] == 'u')
			{
				ft_putnbr_fd(va_arg(args, unsigned int), 1);
			//add num length to bites_printed
			}
			if (format[i + 1] == 'x' || format[i + 1] == 'X')
				ft_put_hexnbr(va_arg(args, unsigned int), format[i + 1], &bites_printed);
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
//the OG printf function returns 0 with printf("");
	if (format[0] == '\0')
		return (0);
	while(format[i])
	{
//check if we need to take into account those error cases :
		if (format[i] == '%' && (!format[i + 1] ||
			!ft_strchr(specifiers_set, format[i + 1])))
			return (-1);
		i++;
	}
	return (1);
}

//ft_putptr : convert to uintptr_t then to unsigned int not recommended because uintptr_t
//is generally an unsigned long so risk of losing data

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
}

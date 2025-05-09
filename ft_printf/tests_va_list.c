#include <stdarg.h>

int	ft_printf_test(const char *format, ...)
{
	va_list	args;
//initializing the variable arguments list 'args' :
//to do before using va_arg 
	va_start(args, format);

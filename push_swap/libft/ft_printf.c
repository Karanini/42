/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:41:41 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/16 12:57:38 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_check_format(const char *format);
static void	ft_converter(va_list *args, char conv_specifier,
				int *bites_printed);

/* ************************************************************************** *
 * This function is a simplified version of the printf(3).
 * It manages the following conversion specifiers : cspdiuxX%
 * The original printf()'s buffer management is not implemented.
 * ***************************************************************************/
int	ft_printf(const char *format, ...)
{
	int		bites_printed;
	va_list	args;
	size_t	i;

	if (ft_check_format(format) == -1 || ft_check_format(format) == 0)
		return (ft_check_format(format));
	va_start(args, format);
	bites_printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i++], 1);
			bites_printed++;
		}
		if (format[i] == '%' && format[i + 1])
		{
			ft_converter(&args, format[i + 1], &bites_printed);
			i = i + 2;
		}
	}
	va_end(args);
	return (bites_printed);
}

/* ************************************************************************** *
 * This function handles the cspdiuxX% conversion specifiers
 * ***************************************************************************/
static void	ft_converter(va_list *args, char conv_specifier, int *bites_printed)
{
	if (conv_specifier == '%')
	{
		ft_putchar_fd('%', 1);
		(*bites_printed)++;
	}
	if (conv_specifier == 'c')
	{
		ft_putchar_fd((unsigned char)va_arg(*args, int), 1);
		(*bites_printed)++;
	}
	if (conv_specifier == 's')
		(*bites_printed) += ft_putstr_fd((char *)va_arg(*args, const char *),
				1);
	if (conv_specifier == 'p')
		ft_putptr(va_arg(*args, void *), bites_printed);
	if (conv_specifier == 'd' || conv_specifier == 'i')
		(*bites_printed) += ft_putnbr_fd(va_arg(*args, int), 1);
	if (conv_specifier == 'u')
		(*bites_printed) += ft_put_uint_fd(va_arg(*args, unsigned int), 1);
	if (conv_specifier == 'x' || conv_specifier == 'X')
		ft_put_hexnbr(va_arg(*args, unsigned int), conv_specifier,
			bites_printed);
}

/* ************************************************************************** *
 * ft_check_format : checks if format is 0 or NULL
 * if ft_printf(NULL) then prints nothing and returns -1
 * if ft_printf("") then prints nothing and returns 0
 * ft_check_format does not check the conversion specifiers since a wrong
 * conv. specifier is an undefined behavior so nothing to implement
 * ***************************************************************************/
static int	ft_check_format(const char *format)
{
	if (format == NULL)
		return (-1);
	if (format[0] == '\0')
		return (0);
	return (1);
}

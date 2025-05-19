/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:48:34 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/19 17:16:13 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* ************************************************************************** *
 * Prints a hex number in the standard output.
 * Lowercase if conv_specifier == 'x' (eg 4eea0)
 * Uppercase if conv_specifier == 'X'(eg 4EEA0)
 * ***************************************************************************/
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

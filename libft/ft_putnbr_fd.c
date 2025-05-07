/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:55:10 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/07 11:45:10 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_and_sign(int *ptr_n, int *ptr_sign)
{
	size_t	divisor;
	size_t	len;

	divisor = 10;
	len = 1;
	if (*ptr_n < 0)
	{
		*ptr_sign = -1;
		*ptr_n *= -1;
		len++;
	}
	while (*ptr_n / divisor)
	{
		len++;
		divisor *= 10;
	}
	return (len);
}

static void	ft_putnbr(int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	size_t	len;

	if (n == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	sign = 1;
	len = ft_len_and_sign(&n, &sign);
	if (sign == -1)
		ft_putchar_fd('-', fd);
	ft_putnbr(n, fd);
}
// int main(void)
// {
// 	ft_putnbr_fd(132,1);
// 	return (0);
// }

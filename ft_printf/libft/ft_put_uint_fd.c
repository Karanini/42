/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:48:40 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/19 17:22:55 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_unsigned(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_put_unsigned(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}

/* ************************************************************************** *
 * Prints an unsigned int n in the file descriptor specified by fd
 * ***************************************************************************/
int	ft_put_uint_fd(unsigned int n, int fd)
{
	int				len;
	unsigned int	tmp;

	len = 1;
	tmp = n;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	ft_put_unsigned(n, fd);
	return (len);
}

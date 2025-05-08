/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:42:17 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/04/30 17:16:57 by bkaras-g         ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	int		sign;
	size_t	len;
	char	*res;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	sign = 1;
	len = ft_len_and_sign(&n, &sign);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}

/*#include <stdio.h>

int	main(void)
{
	char *str = ft_itoa(32);
	printf("32 =%s", str);
	char *str2 = ft_itoa(-32);
	printf("-32 =%s", str2);
	return (0);
}*/

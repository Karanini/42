/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:45:24 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/01 18:35:05 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+') && (nptr[i + 1] == '-'
			|| nptr[i + 1] == '+'))
		return (0);
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

/*#include <stdio.h>

int	main(void)
{
	char str_nb1[] = "-32";
	char str_nb2[] = "++42";
	char str_nb3[] = "3200000";

	int nb1 = ft_atoi(str_nb1);
	int nb2 = ft_atoi(str_nb2);
	int nb3 = ft_atoi(str_nb3);

	printf("nb1 = %d\n", nb1);
	printf("nb2 = %d\n", nb2);
	printf("nb3 = %d\n", nb3);
}*/

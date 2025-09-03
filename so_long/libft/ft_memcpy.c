/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:52:59 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/07 14:50:35 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int d[] = {0, 0, 0};
// 	int s[] = {32, 32, 32};
// 	int i = 0;

// 	ft_memcpy(d, s, sizeof(int) * 3);
// 	while (i < 3)
// 	{
// 		printf("%d\n", d[i]);
// 		i++;
// 	}

// 	printf("memcpy dest==NULL && src==NULL %p",
//		memcpy(((void*)0), ((void*)0), 3));
// 	printf("ft_memcpy dest==NULL && src==NULL %p",
//		ft_memcpy(((void*)0), ((void*)0), 3));

// 	return (0);
// }

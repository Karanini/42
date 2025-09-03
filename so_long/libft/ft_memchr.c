/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:51:30 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/01 18:16:31 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;
	unsigned char		c1;
	size_t				i;

	s1 = (const unsigned char *)s;
	c1 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == c1)
			return ((void *)(s1 + i));
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	char s[] = {0, 1, 2, 3, 4, 5};
	unsigned char *res = ft_memchr(s, 2 + 256, 3);
	printf("res=%s", res);
	return (0);
}*/

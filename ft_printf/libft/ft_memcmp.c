/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:51:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/04/30 17:17:00 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1a;
	unsigned char	*s2a;

	i = 0;
	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && s1a[i] == s2a[i])
		i++;
	if (i == n)
		return (0);
	else
		return (s1a[i] - s2a[i]);
}

/*int	main(int argc, char *argv[])
{
	(void)argc;
	printf("res : %d\n", ft_memcmp(argv[1], argv[2], 5));
	printf("res OG : %d\n", memcmp(argv[1], argv[2], 5));
	return (0);
}*/

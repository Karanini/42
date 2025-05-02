/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:57:21 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/04/30 17:17:04 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int main(void)
// {
// 	int	i;
// 	int	len;
// 	i = 0;
// 	int tab[] = {2, 3, 4};
// 	len = sizeof(int) * 3;
// 	ft_memset(tab, 0, len);
// 	while (i < 3)
// 	{
// 		printf("%d\n", tab[i]);
// 		i++;
// 	}
// 	printf("len : %d", len);
// 	return (0);
// }

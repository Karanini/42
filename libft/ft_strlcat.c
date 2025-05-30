/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:00:30 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/01 18:33:49 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (dsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dsize <= dst_len)
		return (src_len + dsize);
	while (src[i] && i < (dsize - dst_len - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char str1[] = "Trump";
// 	char str1a[18] = "Trump";
// 	char str1b[] = "Trump";
// 	char str1c[18] = "Trump";
// 	char str2[] = "Degage";
// 	char str3[] = "Fous le camp";
// 	printf("strlcat coded : \n");
// 	printf("%zu ", ft_strlcat(str1, str2, 3));
// 	printf("%s\n", str1);
// 	printf("%zu ", ft_strlcat(str1a, str3, 18));
// 	printf("%s\n", str1a);
// 	printf("strlcat original : \n");
// 	printf("%zu ", strlcat(str1b, str2, 3));
// 	printf("%s\n", str1b);
// 	printf("%zu ", strlcat(str1c, str3, 18));
// 	printf("%s\n", str1c);

// }

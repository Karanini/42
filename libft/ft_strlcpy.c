/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:00:42 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/04/30 17:17:46 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		src_len;
	size_t	j;

	src_len = ft_strlen(src);
	j = 0;
	if (size == 0)
		return (src_len);
	while (src[j] && j < size - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (src_len);
}

/*int	main(void)
{
	char	d[2];
	char	s[] = "Soleil";

	ft_strlcpy(d, s, 2);
	printf("%s\n", d);
	return (0);
}
*/

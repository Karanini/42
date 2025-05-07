/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:05:03 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/07 14:49:45 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	size_t			s_len;
	unsigned char	ch;

	ch = (unsigned char)c;
	s_len = ft_strlen(s);
	i = s_len;
	if (ch == '\0')
		return ((char *)(s + s_len));
	while (i-- > 0)
	{
		if (s[i] == ch)
			return ((char *)(s + i));
	}
	return (NULL);
}
// #include <stdio.h>
// int main(void)
// {
// 	printf("%s\n", ft_strrchr("teste",'\0'));
// 	return (0);
// }

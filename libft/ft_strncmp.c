/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:00:56 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/07 11:16:20 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	i = 0;
	s1b = (unsigned char *)s1;
	s2b = (unsigned char *)s2;
	while (s1b[i] && s2b[i] && s1b[i] == s2b[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int	main(int argc, char *argv[])
{
	(void)argc;
	printf("res : %d\n", ft_strncmp(argv[1], argv[2], 5));
	printf("res OG : %d\n", strncmp(argv[1], argv[2], 5));
	return (0);
}*/
